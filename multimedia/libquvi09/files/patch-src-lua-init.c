--- src/lua/init.c.orig
+++ src/lua/init.c
@@ -80,10 +80,17 @@ QuviError l_init(_quvi_t q)
     return (QUVI_ERROR_LUA_INIT);
 
   luaL_openlibs(q->handle.lua);
+#if LUA_VERSION_NUM < 502
   luaL_register(q->handle.lua, "quvi", quvi_reg_meth);
   luaL_register(q->handle.lua, "quvi.http", quvi_http_reg_meth);
   luaL_register(q->handle.lua, "quvi.crypto", quvi_crypto_reg_meth);
   luaL_register(q->handle.lua, "quvi.base64", quvi_base64_reg_meth);
+#else
+  luaL_newlib(q->handle.lua, quvi_reg_meth);
+  luaL_newlib(q->handle.lua, quvi_http_reg_meth);
+  luaL_newlib(q->handle.lua, quvi_crypto_reg_meth);
+  luaL_newlib(q->handle.lua, quvi_base64_reg_meth);
+#endif
 
   return (QUVI_OK);
 }
