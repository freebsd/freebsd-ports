--- Sockets-config.cpp.orig	Sun Jan 16 02:23:14 2005
+++ Sockets-config.cpp	Sun Jan 16 02:26:07 2005
@@ -3,6 +3,10 @@
 CFLAGS =	-Wall -g -O2 $(INCLUDE) -MD -D_VERSION='"$(VERSION)"' 
 # manual autoconf ....
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 # uncomment if your operating system is linux, mac os x, or solaris
 #CFLAGS +=	-DLINUX
 #CFLAGS +=	-DMACOSX 
@@ -19,6 +23,9 @@
 	printf(" -D_VERSION='\"%s\"'", _VERSION);
 #ifdef LINUX
 	printf(" -DLINUX");
+#endif
+#if defined __FreeBSD__
+	printf(" -DFREEBSD");
 #endif
 #ifdef MACOSX
 	printf(" -DMACOSX");
