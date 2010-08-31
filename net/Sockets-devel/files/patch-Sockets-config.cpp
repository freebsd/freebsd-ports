--- Sockets-config.cpp.orig	Sun Sep 25 02:42:19 2005
+++ Sockets-config.cpp	Sun Sep 25 02:44:08 2005
@@ -1,8 +1,12 @@
 #include <stdio.h>
 /*
-CFLAGS =	-Wall -g -O2 $(INCLUDE) -MD -D_VERSION='"$(VERSION)"' 
+CFLAGS =	-Wall -g $(INCLUDE) -MD -D_VERSION='"$(VERSION)"' 
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
