--- transport.hxx.orig	2008-03-01 10:34:43 UTC
+++ transport.hxx
@@ -483,7 +483,7 @@ public:
     {	return 1;   }
 };
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 
 #include <sys/ioctl.h>
 #include <camlib.h>
