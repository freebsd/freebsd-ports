--- sources/math/gnulib.h.orig	Sun Feb  9 01:54:27 2003
+++ sources/math/gnulib.h	Sun Feb  9 01:56:12 2003
@@ -32,9 +32,6 @@
 #ifndef GNULIB_H
 #define GNULIB_H
 
-#ifdef __GNUG__
-#include <_G_config.h>
-#endif   // __GNUG__
 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
@@ -46,11 +43,6 @@
 #include <errno.h>
 #include <fcntl.h>
 
-#ifdef __GNUG__
-extern "C" {
-int strcasecmp _G_ARGS((const char*, const char*));
-}
-#endif   // __GNUG__
 
 
 #include <math.h>
