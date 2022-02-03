--- external/lua/src/lapi.c.orig	2021-11-12 08:57:25 UTC
+++ external/lua/src/lapi.c
@@ -451,7 +451,7 @@ LUA_API lua_State *lua_tothread (lua_State *L, int idx
 LUA_API const void *lua_topointer (lua_State *L, int idx) {
   const TValue *o = index2value(L, idx);
   switch (ttypetag(o)) {
-    case LUA_VLCF: return cast_voidp(cast_sizet(fvalue(o)));
+    case LUA_VLCF: return cast_voidp(cast_intptrt(fvalue(o)));
     case LUA_VUSERDATA: case LUA_VLIGHTUSERDATA:
       return touserdata(o);
     default: {
