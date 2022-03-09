--- src/common_audio/wav_header.cc.orig	2022-02-09 19:21:53 UTC
+++ src/common_audio/wav_header.cc
@@ -26,10 +26,6 @@
 namespace webrtc {
 namespace {
 
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Code not working properly for big endian platforms."
-#endif
-
 #pragma pack(2)
 struct ChunkHeader {
   uint32_t ID;
@@ -119,9 +115,22 @@ uint32_t PackFourCC(char a, char b, char c, char d) {
   return packed_value;
 }
 
+#ifdef WEBRTC_ARCH_LITTLE_ENDIAN
 std::string ReadFourCC(uint32_t x) {
   return std::string(reinterpret_cast<char*>(&x), 4);
 }
+#else
+static inline uint32_t ReadLE32(uint32_t x) {
+  return ((x << 24) & 0xFF000000)
+       | ((x <<  8) & 0x00FF0000)
+       | ((x >>  8) & 0x0000FF00)
+       | ((x >> 24) & 0x000000FF);
+}
+std::string ReadFourCC(uint32_t x) {
+  x = ReadLE32(x);
+  return std::string(reinterpret_cast<char*>(&x), 4);
+}
+#endif
 
 uint16_t MapWavFormatToHeaderField(WavFormat format) {
   switch (format) {
