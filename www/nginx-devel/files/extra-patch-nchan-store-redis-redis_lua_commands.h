--- ../nchan-1.2.7/src/store/redis/redis_lua_commands.h.orig	2020-09-30 23:51:52.116513000 +0800
+++ ../nchan-1.2.7/src/store/redis/redis_lua_commands.h	2020-09-30 23:52:11.164617000 +0800
@@ -63,7 +63,7 @@ typedef struct {
   redis_lua_script_t subscriber_unregister;
 
 } redis_lua_scripts_t;
-redis_lua_scripts_t redis_lua_scripts;
-const int redis_lua_scripts_count;
+extern redis_lua_scripts_t redis_lua_scripts;
+extern const int redis_lua_scripts_count;
 #define REDIS_LUA_SCRIPTS_EACH(script) \
 for((script)=(redis_lua_script_t *)&redis_lua_scripts; (script) < (redis_lua_script_t *)(&redis_lua_scripts + 1); (script)++) 
