--- m4/mk.m4.orig	2019-05-16 20:09:11 UTC
+++ m4/mk.m4
@@ -90,8 +90,10 @@ AC_DEFUN([MK_AM_OPENSSL], [
                 [SSL toolkit @<:@default=check@:>@])
               ],
               [
-                CPPFLAGS="$CPPFLAGS -I$withval/include"
-                LDFLAGS="$LDFLAGS -L$withval/lib"
+		if test ${with_openssl} != /usr; then
+                  CPPFLAGS="$CPPFLAGS -I$withval/include"
+                  LDFLAGS="$LDFLAGS -L$withval/lib"
+		fi
               ],
               [
 	        if test -d /usr/local/Cellar/openssl; then
