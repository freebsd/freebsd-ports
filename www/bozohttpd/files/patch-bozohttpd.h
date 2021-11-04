--- bozohttpd.h.orig	2021-02-28 05:20:51 UTC
+++ bozohttpd.h
@@ -44,8 +44,8 @@
 #include <lua.h>
 #endif
 
-#ifndef NO_BLOCKLIST_SUPPORT
-#include <blocklist.h>
+#ifndef NO_BLACKLIST_SUPPORT
+#include <blacklist.h>
 void pfilter_notify(const int, const int);
 #endif
 
@@ -129,7 +129,7 @@ typedef struct bozohttpd_t {
 	unsigned	ssl_timeout;	/* ssl timeout */
 	unsigned	initial_timeout;/* first line timeout */
 	unsigned	header_timeout;	/* header lines timeout */
-	unsigned	request_timeout;/* total session timeout */
+	int		request_timeout;/* total session timeout */
 #ifndef NO_LUA_SUPPORT
 	int		 process_lua;	/* use the Lua handler */
 	SIMPLEQ_HEAD(, lua_state_map)	lua_states;
