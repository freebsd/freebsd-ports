--- src/capture.c.orig	Mon Mar 15 18:34:42 2004
+++ src/capture.c	Sun Jan  2 18:00:09 2005
@@ -662,7 +662,7 @@
 #ifdef HAVE_FDATASYNC
                 fdatasync(fileno(fp));
 #else
-                fsync(fileno(fp));
+                fsync(fileno((FILE *) fp));
 #endif // HAVE_FDATASYNC
         } 
         
