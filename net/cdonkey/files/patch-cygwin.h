--- cygwin.h.orig	Tue Apr 29 10:32:56 2003
+++ cygwin.h	Tue Apr 29 10:33:16 2003
@@ -110,8 +110,8 @@
 	#define HAVE_SIGHUP	1
 	#define HAVE_SIGINT	1
 	#define HAVE_SIGPIPE	1
-	typedef unsigned long long uint64_t;
-	typedef long long int64_t;
+//	typedef unsigned long long uint64_t;
+//	typedef long long int64_t;
 	#define closesocket             close
 	#define ioctlsocket             ioctl
 #endif
