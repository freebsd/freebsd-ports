--- platforms.h.orig	2016-10-01 08:55:57 UTC
+++ platforms.h
@@ -50,11 +50,12 @@
 
 #include <netinet/sctp.h>
 #include <sys/param.h>
+#include <paths.h>
 #if __FreeBSD_version >= 1001000
 #include <netinet/udplite.h>
 #endif
 #define USE_LIBPCAP             1
-#define TUN_PATH                "/dev/tun0"
+#define TUN_PATH                _PATH_DEV "tun0"
 #define TUN_DEV                 "tun0"
 #define HAVE_TCP_INFO           1
 #if (__FreeBSD_version < 1000000 && __FreeBSD_version > 902000) || __FreeBSD_version > 1000028
