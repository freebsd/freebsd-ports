--- src/compressor/snappy/SnappyCompressor.h.orig	2020-08-10 20:15:22 UTC
+++ src/compressor/snappy/SnappyCompressor.h
@@ -15,6 +15,7 @@
 #ifndef CEPH_SNAPPYCOMPRESSOR_H
 #define CEPH_SNAPPYCOMPRESSOR_H
 
+#include <cstdint>
 #include <snappy.h>
 #include <snappy-sinksource.h>
 #include "common/config.h"
@@ -96,7 +97,7 @@ class SnappyCompressor : public Compressor {
     if (qat_enabled)
       return qat_accel.decompress(p, compressed_len, dst);
 #endif
-    snappy::uint32 res_len = 0;
+    std::uint32_t res_len = 0;
     BufferlistSource source_1(p, compressed_len);
     if (!snappy::GetUncompressedLength(&source_1, &res_len)) {
       return -1;
