--- third_party/ots/include/opentype-sanitiser.h.orig	2014-10-10 09:15:53 UTC
+++ third_party/ots/include/opentype-sanitiser.h
@@ -22,6 +22,7 @@
 #else
 #include <arpa/inet.h>
 #include <stdint.h>
+#include <sys/types.h>
 #endif
 
 #include <algorithm>  // for std::min
