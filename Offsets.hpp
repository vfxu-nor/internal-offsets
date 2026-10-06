//version-02c37bc51a384b8f

#pragma once

#include <cstdint>
#include <Windows.h>

struct lua_State;
struct YieldState;
struct YieldingLuaThread;

#define REBASE(Address) (Address + reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    const uintptr_t Print = REBASE(0x1d2eeb0);
    const uintptr_t OpcodeLookupTable = REBASE(0x6f67bf0);
    const uintptr_t ScriptContextResume = REBASE(0x42A7E60);
    const uintptr_t GetLuaStateForInstance = REBASE(0x41FE9B0);

    namespace Luau
    {
        inline const uintptr_t Luau_Execute = REBASE(0x2681d50);
        inline const uintptr_t LuaO_NilObject = REBASE(0x6507cd8);
        inline const uintptr_t LuaH_DummyNode = REBASE(0x6504798);
        inline const uintptr_t LuaD_Throw = REBASE(0x26520b0);
    }

    namespace DataModel
    {
        inline const uintptr_t FakeDataModelPointer = REBASE(0x8b54980);
        inline const uintptr_t FakeDataModelToDataModel = 0x1F8;
        inline const uintptr_t ScriptContext = 0x440;
        inline const uintptr_t GameLoaded = 0x5D0;
        inline const uintptr_t Children = 0x78;
    }

    namespace ExtraSpace
    {
        const uintptr_t RequireBypass = 0xad0;
        const uintptr_t ScriptContextToResume = 0xA38;
    }
}

namespace Roblox
{
    inline auto Print = (uintptr_t(*)(int, const char*, ...))Offsets::Print;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau::Luau_Execute;
    inline auto GetLuaStateForInstance = (lua_State * (__fastcall*)(uint64_t, uint64_t*, uint64_t*))Offsets::GetLuaStateForInstance;
    inline auto ScriptContextResume = (uint64_t(__fastcall*)(uint64_t, YieldState*, YieldingLuaThread**, uint32_t, uint8_t, uint64_t))Offsets::ScriptContextResume;

    inline auto LuaD_Throw = (void(__fastcall*)(lua_State*, int))Offsets::Luau::LuaD_Throw;
}
