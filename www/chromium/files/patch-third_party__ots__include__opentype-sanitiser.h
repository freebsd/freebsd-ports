--- third_party/ots/include/opentype-sanitiser.h.orig	2012-04-12 09:04:04.000000000 +0200
+++ third_party/ots/include/opentype-sanitiser.h	2012-04-29 22:09:44.000000000 +0200
@@ -22,6 +22,7 @@
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>  // for std::min
