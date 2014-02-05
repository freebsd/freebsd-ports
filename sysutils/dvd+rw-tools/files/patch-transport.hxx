--- transport.hxx.orig	2013-01-15 00:38:53.673146000 +0100
+++ transport.hxx	2013-01-15 00:39:31.283199000 +0100
@@ -483,7 +483,7 @@
     {	return 1;   }
 };
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #include <sys/ioctl.h>
 #include <camlib.h>
