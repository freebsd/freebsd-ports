--- miltertest/miltertest.c.orig	2014-03-20 04:36:13 UTC
+++ miltertest/miltertest.c
@@ -4009,7 +4009,7 @@ main(int argc, char **argv)
 	}
 
 	/* register functions */
-#if LUA_VERSION_NUM == 502
+#if (LUA_VERSION_NUM == 502 || LUA_VERSION_NUM == 503)
         luaL_newlib(l, mt_library);
 	lua_setglobal(l, "mt");
 #else /* LUA_VERSION_NUM == 502 */
@@ -4163,7 +4163,7 @@ main(int argc, char **argv)
 	lua_setglobal(l, "SMFIF_SETSYMLIST");
 #endif /* SMFIF_SETSYMLIST */
 
-#if LUA_VERSION_NUM == 502
+#if (LUA_VERSION_NUM == 502 || LUA_VERSION_NUM == 503)
 	switch (lua_load(l, mt_lua_reader, (void *) &io,
 	                 script == NULL ? "(stdin)" : script, NULL))
 #else /* LUA_VERSION_NUM == 502 */
