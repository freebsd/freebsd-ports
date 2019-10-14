--- src/lua/lua_regexp.c.orig	2019-10-11 16:56:09 UTC
+++ src/lua/lua_regexp.c
@@ -889,16 +889,18 @@ lua_load_regexp (lua_State * L)
 void
 luaopen_regexp (lua_State * L)
 {
+	if (!regexp_static_pool) {
+		regexp_static_pool = rspamd_mempool_new (rspamd_mempool_suggest_size (),
+				"regexp_lua_pool");
+	}
+
 	rspamd_lua_new_class (L, "rspamd{regexp}", regexplib_m);
 	lua_pop (L, 1);
 	rspamd_lua_add_preload (L, "rspamd_regexp", lua_load_regexp);
 }
 
-RSPAMD_CONSTRUCTOR (lua_re_static_pool_ctor) {
-	regexp_static_pool = rspamd_mempool_new (rspamd_mempool_suggest_size (),
-			"regexp_lua_pool");
-}
-
 RSPAMD_DESTRUCTOR (lua_re_static_pool_dtor) {
-	rspamd_mempool_delete (regexp_static_pool);
+	if (regexp_static_pool) {
+		rspamd_mempool_delete (regexp_static_pool);
+	}
 }
\ No newline at end of file
