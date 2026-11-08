-- remove vague and wrong code discovering Lua,
-- in order to find the Lua version that we've set in the port's Makefile

--- cmake/thirdparty/FindLUA.cmake.orig	2026-08-28 22:06:10 UTC
+++ cmake/thirdparty/FindLUA.cmake
@@ -24,14 +24,7 @@ set(ENV{LUA_DIR} ${LUA_DIR})
 # Uncomment the following for more debug output in FindLUA
 #set(LUA_Debug TRUE)
 
-# HACK: Workaround for lua@5.4 and older versions of cmake (e.g. 3.16)
-# which did not account for versions of lua beyond 5.3
-string(FIND ${LUA_DIR} lua-5.4 _is_lua_5_4)
-if(NOT ${_is_lua_5_4} EQUAL -1)
-    find_package(Lua 5.4 EXACT REQUIRED) 
-else()
-    find_package(Lua REQUIRED) 
-endif()
+find_package(Lua ${FREEBSD_LUA_VER} EXACT REQUIRED) 
 
 if(NOT LUA_FOUND)
     message(FATAL_ERROR "LUA_DIR is not a path to a valid Lua install")
