--- src/3rdparty/chromium/third_party/webrtc/common_audio/wav_header.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/common_audio/wav_header.cc
@@ -86,7 +86,26 @@ static inline std::string ReadFourCC(uint32_t x) {
   return std::string(reinterpret_cast<char*>(&x), 4);
 }
 #else
-#error "Write be-to-le conversion functions"
+static inline void WriteLE16(uint16_t* f, uint16_t x) {
+  *f = __builtin_bswap16(x);
+}
+static inline void WriteLE32(uint32_t* f, uint32_t x) {
+  *f = __builtin_bswap32(x);
+}
+static inline void WriteFourCC(uint32_t* f, char a, char b, char c, char d) {
+  *f = static_cast<uint32_t>(d) | static_cast<uint32_t>(c) << 8 |
+       static_cast<uint32_t>(b) << 16 | static_cast<uint32_t>(a) << 24;
+}
+
+static inline uint16_t ReadLE16(uint16_t x) {
+  return __builtin_bswap16(x);
+}
+static inline uint32_t ReadLE32(uint32_t x) {
+  return __builtin_bswap32(x);
+}
+static inline std::string ReadFourCC(uint32_t x) {
+  return std::string(reinterpret_cast<char*>(&x), 4);
+}
 #endif
 
 static inline uint32_t RiffChunkSize(size_t bytes_in_payload) {
