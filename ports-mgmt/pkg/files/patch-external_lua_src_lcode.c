--- external/lua/src/lcode.c.orig	2021-09-30 20:43:46 UTC
+++ external/lua/src/lcode.c
@@ -591,7 +591,7 @@ static int stringK (FuncState *fs, TString *s) {
 */
 static int luaK_intK (FuncState *fs, lua_Integer n) {
   TValue k, o;
-  setpvalue(&k, cast_voidp(cast_sizet(n)));
+  setpvalue(&k, cast_voidp(cast_intptrt(n)));
   setivalue(&o, n);
   return addk(fs, &k, &o);
 }
