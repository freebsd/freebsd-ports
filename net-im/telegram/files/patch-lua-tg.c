--- lua-tg.c.orig	2016-12-27 02:26:05 UTC
+++ lua-tg.c
@@ -661,9 +661,9 @@ struct lua_arg {
 struct lua_arg lua_ptr[MAX_LUA_COMMANDS];
 static int pos;
 
-static inline tgl_peer_t *get_peer (const char *s) { 
-  return tgl_peer_get_by_name (TLS, s);
-}
+// static inline tgl_peer_t *get_peer (const char *s) { 
+//   return tgl_peer_get_by_name (TLS, s);
+// }
   
 enum lua_query_type {
   lq_contact_list,
