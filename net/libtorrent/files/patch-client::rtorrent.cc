--- client/rtorrent.cc.old	Fri Jan  7 15:04:15 2005
+++ client/rtorrent.cc	Fri Jan  7 15:04:57 2005
@@ -19,9 +19,9 @@
 #include "curl_get.h"
 
 // Uncomment this if your system doesn't have execinfo.h
-#define USE_EXECINFO
+//#define USE_EXECINFO
 
-#ifdef USE_EXECINFO
+#ifdef USE_EXECINFO 
 #include <execinfo.h>
 #endif
 
