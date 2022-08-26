- Lua related path adjustments

--- cmake/thirdparty/FindLUA.cmake.orig	2022-08-21 08:14:54 UTC
+++ cmake/thirdparty/FindLUA.cmake
@@ -23,7 +23,7 @@ endif()
 # Find includes directory
 find_path( LUA_INCLUDE_DIR lua.hpp
            PATHS  ${LUA_DIR}/include/
-                  ${LUA_DIR}/include/lua
+                  ${LUA_DIR}/include/lua${FREEBSD_LUA_VER_STR}
            NO_DEFAULT_PATH
            NO_CMAKE_ENVIRONMENT_PATH
            NO_CMAKE_PATH
@@ -31,8 +31,8 @@ find_path( LUA_INCLUDE_DIR lua.hpp
            NO_CMAKE_SYSTEM_PATH)
 
 # Find libraries
-find_library( LUA_LIBRARY NAMES lua liblua
-              PATHS ${LUA_DIR}/lib
+find_library( LUA_LIBRARY NAMES lua-${FREEBSD_LUA_VER} liblua
+	PATHS ${LUA_DIR}/lib
               NO_DEFAULT_PATH
               NO_CMAKE_ENVIRONMENT_PATH
               NO_CMAKE_PATH
