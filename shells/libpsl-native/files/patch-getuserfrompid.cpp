--- src/getuserfrompid.cpp.orig	2024-06-25 19:56:08.189198000 +0200
+++ src/getuserfrompid.cpp	2024-06-25 19:57:35.956077000 +0200
@@ -11,7 +11,7 @@
 #include <sstream>
 #include <errno.h>
 
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
 #include <sys/sysctl.h>
 #elif HAVE_SYSCONF
 // do nothing
