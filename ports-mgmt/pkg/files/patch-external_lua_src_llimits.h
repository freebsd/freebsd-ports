--- external/lua/src/llimits.h.orig	2021-11-12 08:57:25 UTC
+++ external/lua/src/llimits.h
@@ -132,7 +132,7 @@ typedef LUAI_UACINT l_uacInt;
 #define cast_char(i)	cast(char, (i))
 #define cast_charp(i)	cast(char *, (i))
 #define cast_sizet(i)	cast(size_t, (i))
-
+#define cast_intptrt(i)	cast(intptr_t, (i))
 
 /* cast a signed lua_Integer to lua_Unsigned */
 #if !defined(l_castS2U)
