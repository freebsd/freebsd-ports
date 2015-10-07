--- src/mod_cml_lua.c.orig	2015-07-26 10:36:36 UTC
+++ src/mod_cml_lua.c
@@ -28,6 +28,10 @@ typedef char HASHHEX[HASHHEXLEN+1];
 #include <lualib.h>
 #include <lauxlib.h>
 
+#if LUA_VERSION_NUM >= 502
+#define LUA_GLOBALSINDEX LUA_REGISTRYINDEX
+#endif
+
 typedef struct {
 	stream st;
 	int done;
@@ -291,7 +295,11 @@ int cache_parse_lua(server *srv, connect
 	lua_settable(L, LUA_GLOBALSINDEX);
 
 	/* load lua program */
+#if LUA_VERSION_NUM >= 502
+	if (lua_load(L, load_file, &rm, fn->ptr, NULL) || lua_pcall(L,0,1,0)) {
+#else
 	if (lua_load(L, load_file, &rm, fn->ptr) || lua_pcall(L,0,1,0)) {
+#endif
 		log_error_write(srv, __FILE__, __LINE__, "s",
 				lua_tostring(L,-1));
 
