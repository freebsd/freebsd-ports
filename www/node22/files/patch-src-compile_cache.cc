Obtained from:	https://github.com/nodejs/node/pull/54528

--- src/compile_cache.cc.orig	2024-09-03 03:18:45 UTC
+++ src/compile_cache.cc
@@ -8,6 +8,10 @@
 #include "path.h"
 #include "zlib.h"
 
+#ifdef NODE_IMPLEMENTS_POSIX_CREDENTIALS
+#include <unistd.h>  // getuid
+#endif
+
 namespace node {
 std::string Uint32ToHex(uint32_t crc) {
   std::string str;
