--- mpifileutils/src/common/mfu_bz2.h.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_bz2.h
@@ -1,6 +1,7 @@
 #ifndef MFU_BZ2_H
 #define MFU_BZ2_H
 
+int mfu_compress_bz2_static(const char* src_name, const char* dst_name, int b_size);
 int mfu_compress_bz2(const char* src_name, const char* dst_name, int b_size);
 int mfu_decompress_bz2(const char* src_name, const char* dst_name);
 
