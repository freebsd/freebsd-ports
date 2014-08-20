--- ./common_m4/compiler_options.m4.orig	2014-08-20 10:21:07.000000000 -0400
+++ ./common_m4/compiler_options.m4	2014-08-20 10:21:17.000000000 -0400
@@ -28,7 +28,7 @@
 
     CFLAGS="$CFLAGS -std=c99 -fno-strict-aliasing"
     CPPFLAGS="$CPPFLAGS -fno-strict-aliasing"
-    CWARNINGS="$CWARNINGS -Wall -Werror -Wwrite-strings -Wformat -fdiagnostics-show-option -Wextra -Wformat-security -Wsign-compare -Wcast-align -Wno-unused-parameter"
+    CWARNINGS="$CWARNINGS -Wall -Wwrite-strings -Wformat -fdiagnostics-show-option -Wextra -Wformat-security -Wsign-compare -Wcast-align -Wno-unused-parameter"
     if test "x$NOT_PEDANTIC" = "x"; then
         CWARNINGS="$CWARNINGS -pedantic"
     fi
