--- nx-X11/lib/xtrans/Xtranssock.c.orig	Wed Mar  3 19:47:29 2004
+++ nx-X11/lib/xtrans/Xtranssock.c	Wed Sep  1 22:39:47 2004
@@ -2118,11 +2118,11 @@
          * platforms as well.
          */
 
-        #ifndef __sun
+	/*        #ifndef __sun */
 
-        sa.sa_restorer = NULL;
+	/*        sa.sa_restorer = NULL; */
 
-        #endif
+        /* #endif */
 
         sigemptyset(&(sa.sa_mask));
 
