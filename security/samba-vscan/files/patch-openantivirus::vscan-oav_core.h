--- openantivirus/vscan-oav_core.h.orig	Thu Feb 26 10:28:04 2004
+++ openantivirus/vscan-oav_core.h	Thu Feb 26 10:28:16 2004
@@ -1,6 +1,7 @@
 #ifndef __VSCAN_OAV_CORE_H_
 #define __VSCAN_OAV_CORE_H_
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
