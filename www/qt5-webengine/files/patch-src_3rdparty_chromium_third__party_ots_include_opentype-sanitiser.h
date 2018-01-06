--- src/3rdparty/chromium/third_party/ots/include/opentype-sanitiser.h.orig	2017-01-26 00:49:30 UTC
+++ src/3rdparty/chromium/third_party/ots/include/opentype-sanitiser.h
@@ -22,6 +22,7 @@ typedef unsigned __int64 uint64_t;
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>
