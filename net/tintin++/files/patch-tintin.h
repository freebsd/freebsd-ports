--- tintin.h.orig	2020-10-09 12:23:24 UTC
+++ tintin.h
@@ -98,6 +98,10 @@
 #include <sys/stat.h>
 #endif
 
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+
 #if !defined(SO_PEERCRED)
 	#define SO_PEERCRED 17
 #endif
