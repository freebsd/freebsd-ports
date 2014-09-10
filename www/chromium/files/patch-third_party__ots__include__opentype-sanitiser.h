--- ./third_party/ots/include/opentype-sanitiser.h.orig	2014-08-20 21:03:55.000000000 +0200
+++ ./third_party/ots/include/opentype-sanitiser.h	2014-08-22 15:06:27.000000000 +0200
@@ -22,6 +22,7 @@
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>  // for std::min
