--- libannex/api_if.c.orig	Mon Oct 13 01:49:30 2003
+++ libannex/api_if.c	Mon Oct 13 01:49:51 2003
@@ -180,8 +180,10 @@
 #define recvmsg_func recvmsg
 #endif
 
+#ifndef __FreeBSD__
 extern int sendmsg_func();
 extern int recvmsg_func();
+#endif
 
 #ifdef _WIN32
 #define XylogicsWSAGetLastError()	\
