--- bjoern/portable_sendfile.c.orig	2014-11-11 20:31:07 UTC
+++ bjoern/portable_sendfile.c
@@ -18,9 +18,7 @@
     return len;
   }
 
-#elif defined __FreeBSD__
-
-  /* FreeBSD */
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
   #include <sys/socket.h>
   #include <sys/types.h>
