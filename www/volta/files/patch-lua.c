--- ./lua.c.orig	2012-05-04 06:21:02.000000000 +0200
+++ ./lua.c	2014-01-10 09:17:46.000000000 +0100
@@ -79,14 +79,12 @@
 	luaL_openlibs( lua ); /* include lua standard libraries */
 
 	/* Predeclare the request table. */
-	lua_pushstring( lua, "request" );
 	lua_createtable( lua, 0, 7 );
-	lua_settable( lua, LUA_GLOBALSINDEX );
+	lua_setglobal(lua, "request");
 
 	/* Predeclare a table for shared data */
-	lua_pushstring( lua, "shared" );
 	lua_newtable( lua );
-	lua_settable( lua, LUA_GLOBALSINDEX );
+	lua_setglobal(lua, "shared");
 
 	/* replace the lua print() function with one that calls debug() instead */
 	lua_register( lua, "print", luaV_print );
@@ -97,7 +95,8 @@
     lua_setfield( lua, -2, "__newindex");
     lua_pushboolean( lua, 0 );
     lua_setfield( lua, -2, "__metatable");
-    lua_setmetatable( lua, LUA_GLOBALSINDEX );
+	lua_setmetatable(lua, -2);
+
 
 	lua_settop( lua, 0 );  /* wipe the stack */
 	return( lua );
@@ -111,7 +110,7 @@
 void
 luaV_setup_request( parsed *request )
 {
-	lua_getfield( v.lua, LUA_GLOBALSINDEX, "request" );
+	lua_getglobal(v.lua, "request");
 	lua_pushstring( v.lua, request->scheme );
 	lua_setfield( v.lua, 1, "scheme" );
 	lua_pushstring( v.lua, request->host );
