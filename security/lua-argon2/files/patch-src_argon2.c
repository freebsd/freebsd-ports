--- src/argon2.c.orig	2022-09-25 20:11:00 UTC
+++ src/argon2.c
@@ -486,7 +486,7 @@ static const luaL_Reg largon2[] = { { "verify", largon
                                     { NULL, NULL } };

-int
+LUALIB_API int
 luaopen_argon2(lua_State *L)
 {
     lua_newtable(L);
