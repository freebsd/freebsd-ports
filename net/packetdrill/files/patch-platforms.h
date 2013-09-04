--- platforms.h.orig	2013-07-21 04:53:41.000000000 +0900
+++ platforms.h	2013-09-04 10:34:56.000000000 +0900
@@ -43,12 +43,14 @@
 
 #if defined(__FreeBSD__)
 
+#include <paths.h>
 #define USE_LIBPCAP             1
-#define TUN_PATH                "/dev/tun0"
+#define TUN_PATH                _PATH_DEV "tun0"
 #define TUN_DEV                 "tun0"
 
 #define HAVE_TCP_INFO           1
 
+#include "ports_config.h"
 #include "open_memstream.h"
 #include "fmemopen.h"
 
