--- opendkim/opendkim-lua.c.orig	2015-02-04 00:31:11 UTC
+++ opendkim/opendkim-lua.c
@@ -282,11 +282,11 @@ dkimf_lua_alloc(void *ud, void *ptr, size_t osize, siz
 		free(ptr);
 		return NULL;
 	}
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	else if (nsize != 0 && ptr == NULL)
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	else if (nsize != 0 && osize == 0)
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 		return malloc(nsize);
 	}
@@ -482,13 +482,13 @@ dkimf_lua_setup_hook(void *ctx, const char *script, si
 	**  Register functions.
 	*/
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	luaL_newlib(l, dkimf_lua_lib_setup);
 	lua_setglobal(l, "odkim");
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	luaL_register(l, "odkim", dkimf_lua_lib_setup);
-# endif /* LUA_VERSION_NUM == 502 */
 	lua_pop(l, 1);
+# endif /* LUA_VERSION_NUM >= 502 */
 
 	/*
 	**  Register constants.
@@ -529,11 +529,11 @@ dkimf_lua_setup_hook(void *ctx, const char *script, si
 	/* import other globals */
 	dkimf_import_globals(ctx, l);
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name, NULL))
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name))
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
@@ -561,7 +561,11 @@ dkimf_lua_setup_hook(void *ctx, const char *script, si
 		io.lua_io_len = 0;
 		io.lua_io_alloc = 0;
 
+#if (LUA_VERSION_NUM >= 503)
+		if (lua_dump(l, dkimf_lua_writer, &io, 0) == 0)
+#else
 		if (lua_dump(l, dkimf_lua_writer, &io) == 0)
+#endif
 		{
 			*keep = (void *) io.lua_io_script;
 			*funclen = io.lua_io_len;
@@ -637,13 +641,13 @@ dkimf_lua_screen_hook(void *ctx, const char *script, s
 	**  Register functions.
 	*/
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	luaL_newlib(l, dkimf_lua_lib_screen);
 	lua_setglobal(l, "odkim");
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	luaL_register(l, "odkim", dkimf_lua_lib_screen);
-# endif /* LUA_VERSION_NUM == 502 */
 	lua_pop(l, 1);
+# endif /* LUA_VERSION_NUM >= 502 */
 
 	/*
 	**  Register constants.
@@ -674,11 +678,11 @@ dkimf_lua_screen_hook(void *ctx, const char *script, s
 	/* import other globals */
 	dkimf_import_globals(ctx, l);
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name, NULL))
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name))
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
@@ -706,7 +710,11 @@ dkimf_lua_screen_hook(void *ctx, const char *script, s
 		io.lua_io_len = 0;
 		io.lua_io_alloc = 0;
 
+#if (LUA_VERSION_NUM >= 503)
+		if (lua_dump(l, dkimf_lua_writer, &io, 0) == 0)
+#else
 		if (lua_dump(l, dkimf_lua_writer, &io) == 0)
+#endif
 		{
 			*keep = (void *) io.lua_io_script;
 			*funclen = io.lua_io_len;
@@ -782,13 +790,13 @@ dkimf_lua_stats_hook(void *ctx, const char *script, si
 	**  Register functions.
 	*/
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	luaL_newlib(l, dkimf_lua_lib_stats);
 	lua_setglobal(l, "odkim");
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	luaL_register(l, "odkim", dkimf_lua_lib_stats);
-# endif /* LUA_VERSION_NUM == 502 */
 	lua_pop(l, 1);
+# endif /* LUA_VERSION_NUM >= 502 */
 
 	/*
 	**  Register constants.
@@ -911,11 +919,11 @@ dkimf_lua_stats_hook(void *ctx, const char *script, si
 	/* import other globals */
 	dkimf_import_globals(ctx, l);
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name, NULL))
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name))
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
@@ -943,7 +951,11 @@ dkimf_lua_stats_hook(void *ctx, const char *script, si
 		io.lua_io_len = 0;
 		io.lua_io_alloc = 0;
 
+#if (LUA_VERSION_NUM >= 503)
+		if (lua_dump(l, dkimf_lua_writer, &io, 0) == 0)
+#else
 		if (lua_dump(l, dkimf_lua_writer, &io) == 0)
+#endif
 		{
 			*keep = (void *) io.lua_io_script;
 			*funclen = io.lua_io_len;
@@ -1019,13 +1031,13 @@ dkimf_lua_final_hook(void *ctx, const char *script, si
 	**  Register functions.
 	*/
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	luaL_newlib(l, dkimf_lua_lib_final);
 	lua_setglobal(l, "odkim");
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	luaL_register(l, "odkim", dkimf_lua_lib_final);
-# endif /* LUA_VERSION_NUM == 502 */
 	lua_pop(l, 1);
+# endif /* LUA_VERSION_NUM >= 502 */
 
 	/*
 	**  Register constants.
@@ -1148,11 +1160,11 @@ dkimf_lua_final_hook(void *ctx, const char *script, si
 	/* import other globals */
 	dkimf_import_globals(ctx, l);
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name, NULL))
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, name))
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
@@ -1180,7 +1192,11 @@ dkimf_lua_final_hook(void *ctx, const char *script, si
 		io.lua_io_len = 0;
 		io.lua_io_alloc = 0;
 
+#if (LUA_VERSION_NUM >= 503)
+		if (lua_dump(l, dkimf_lua_writer, &io, 0) == 0)
+#else
 		if (lua_dump(l, dkimf_lua_writer, &io) == 0)
+#endif
 		{
 			*keep = (void *) io.lua_io_script;
 			*funclen = io.lua_io_len;
@@ -1249,11 +1265,11 @@ dkimf_lua_db_hook(const char *script, size_t scriptlen
 		lua_pushstring(l, query);
 	lua_setglobal(l, "query");
 
-# if LUA_VERSION_NUM == 502
+# if LUA_VERSION_NUM >= 502
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, script, NULL))
-# else /* LUA_VERSION_NUM == 502 */
+# else /* LUA_VERSION_NUM >= 502 */
 	switch (lua_load(l, dkimf_lua_reader, (void *) &io, script))
-# endif /* LUA_VERSION_NUM == 502 */
+# endif /* LUA_VERSION_NUM >= 502 */
 	{
 	  case 0:
 		break;
@@ -1281,7 +1297,11 @@ dkimf_lua_db_hook(const char *script, size_t scriptlen
 		io.lua_io_len = 0;
 		io.lua_io_alloc = 0;
 
+#if (LUA_VERSION_NUM >= 503)
+		if (lua_dump(l, dkimf_lua_writer, &io, 0) == 0)
+#else
 		if (lua_dump(l, dkimf_lua_writer, &io) == 0)
+#endif
 		{
 			*keep = (void *) io.lua_io_script;
 			*funclen = io.lua_io_len;
