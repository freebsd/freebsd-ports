--- src/cdilib.c.orig	Mon Mar  6 17:08:36 2006
+++ src/cdilib.c	Mon May 29 22:28:01 2006
@@ -3948,7 +3948,6 @@
 
 #if ! defined (HAVE_MALLOC_H)
 #  if defined (__sun) || defined (__i386) || defined (__ia64) || defined (SX)
-#    define  HAVE_MALLOC_H
 #  endif
 #endif
 
