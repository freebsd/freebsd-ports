--- shell/hush.c.orig	2026-05-13 02:10:19 UTC
+++ shell/hush.c
@@ -362,7 +362,7 @@
 #if !(defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) \
 	|| defined(__APPLE__) \
     )
-# include <malloc.h>   /* for malloc_trim */
+# include <stdlib.h>   /* for malloc_trim */
 #endif
 #include <glob.h>
 /* #include <dmalloc.h> */
