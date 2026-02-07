--- miltertest/miltertest.c.orig	2014-03-20 04:36:13 UTC
+++ miltertest/miltertest.c
@@ -4009,13 +4009,13 @@ main(int argc, char **argv)
 	}
 
 	/* register functions */
-#if LUA_VERSION_NUM == 502
+#if LUA_VERSION_NUM >= 502
         luaL_newlib(l, mt_library);
 	lua_setglobal(l, "mt");
-#else /* LUA_VERSION_NUM == 502 */
+#else /* LUA_VERSION_NUM >= 502 */
 	luaL_register(l, "mt", mt_library);
-#endif /* LUA_VERSION_NUM == 502 */
 	lua_pop(l, 1);
+#endif /* LUA_VERSION_NUM >= 502 */
 
 	/* register constants */
 	lua_pushnumber(l, MT_HDRINSERT);
@@ -4163,13 +4163,13 @@ main(int argc, char **argv)
 	lua_setglobal(l, "SMFIF_SETSYMLIST");
 #endif /* SMFIF_SETSYMLIST */
 
-#if LUA_VERSION_NUM == 502
+#if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, mt_lua_reader, (void *) &io,
 	                 script == NULL ? "(stdin)" : script, NULL))
-#else /* LUA_VERSION_NUM == 502 */
+#else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, mt_lua_reader, (void *) &io,
 	                 script == NULL ? "(stdin)" : script))
-#endif /* LUA_VERSION_NUM == 502 */
+#endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
