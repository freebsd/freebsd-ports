--- ./third_party/ots/include/opentype-sanitiser.h.orig	2014-04-30 22:43:54.000000000 +0200
+++ ./third_party/ots/include/opentype-sanitiser.h	2014-05-04 14:38:49.000000000 +0200
@@ -22,6 +22,7 @@
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>  // for std::min
