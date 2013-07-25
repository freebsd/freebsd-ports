--- platforms.h.orig	2013-07-24 19:55:39.000000000 +0900
+++ platforms.h	2013-07-24 19:56:36.000000000 +0900
@@ -43,11 +43,15 @@
 
 #if defined(__FreeBSD__)
 
+#include <sys/param.h>
 #define USE_LIBPCAP             1
 #define TUN_PATH                "/dev/tun0"
 #define TUN_DEV                 "tun0"
 
 #define HAVE_TCP_INFO           1
+#if __FreeBSD_version > 1000028
+#define	HAVE_FMEMOPEN		1 
+#endif
 
 #include "open_memstream.h"
 #include "fmemopen.h"
