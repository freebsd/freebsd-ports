--- src/3rdparty/chromium/third_party/perfetto/src/protozero/proto_decoder.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/protozero/proto_decoder.cc
@@ -29,7 +29,8 @@ using namespace proto_utils;
 #define BYTE_SWAP_TO_LE32(x) (x)
 #define BYTE_SWAP_TO_LE64(x) (x)
 #else
-#error Unimplemented for big endian archs.
+#define BYTE_SWAP_TO_LE32(x) __builtin_bswap32(x)
+#define BYTE_SWAP_TO_LE64(x) __builtin_bswap64(x)
 #endif
 
 ProtoDecoder::Field ProtoDecoder::ReadField() {
