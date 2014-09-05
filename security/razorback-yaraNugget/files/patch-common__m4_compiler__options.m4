--- common_m4/compiler_options.m4.orig	2012-01-04 18:17:09 UTC
+++ common_m4/compiler_options.m4
@@ -28,7 +28,7 @@ if test "$GCC" = yes ; then
 
     CFLAGS="$CFLAGS -std=c99 -fno-strict-aliasing"
     CPPFLAGS="$CPPFLAGS -fno-strict-aliasing"
-    CWARNINGS="$CWARNINGS -Wall -Werror -Wwrite-strings -Wformat -fdiagnostics-show-option -Wextra -Wformat-security -Wsign-compare -Wcast-align -Wno-unused-parameter"
+    CWARNINGS="$CWARNINGS -Wall -Wwrite-strings -Wformat -fdiagnostics-show-option -Wextra -Wformat-security -Wsign-compare -Wcast-align -Wno-unused-parameter"
     if test "x$NOT_PEDANTIC" = "x"; then
         CWARNINGS="$CWARNINGS -pedantic"
     fi
