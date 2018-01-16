--- libgrive/src/util/File.cc.orig	2016-01-14 20:51:31 UTC
+++ libgrive/src/util/File.cc
@@ -33,6 +33,10 @@
 #include <sys/types.h>
 #include <fcntl.h>
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <unistd.h>
+#endif
+
 #ifdef WIN32
 	#include <io.h>
 	typedef int ssize_t ;
