Already fixed upstream:
https://github.com/khaledhosny/ots/commit/5d82ccd35fa61f605a43a5433625e379ca0f4018
--- src/3rdparty/chromium/third_party/ots/include/opentype-sanitiser.h.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/third_party/ots/include/opentype-sanitiser.h
@@ -22,6 +22,7 @@ typedef unsigned __int64 uint64_t;
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>
