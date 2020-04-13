--- src/3rdparty/chromium/third_party/perfetto/src/protozero/proto_decoder.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/protozero/proto_decoder.cc
@@ -28,7 +28,8 @@ namespace protozero {
 using namespace proto_utils;
 
 #if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
-#error Unimplemented for big endian archs.
+#define BYTE_SWAP_TO_LE32(x) __builtin_bswap32(x)
+#define BYTE_SWAP_TO_LE64(x) __builtin_bswap64(x)
 #endif
 
 namespace {
