--- src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/bmp/bmp_image_reader.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/image-decoders/bmp/bmp_image_reader.h
@@ -37,6 +37,7 @@
 #include "third_party/blink/renderer/platform/wtf/allocator.h"
 #include "third_party/blink/renderer/platform/wtf/cpu.h"
 #include "third_party/blink/renderer/platform/wtf/noncopyable.h"
+#include "base/sys_byteorder.h"
 
 namespace blink {
 
@@ -50,11 +51,11 @@ class PLATFORM_EXPORT BMPImageReader final {
   // Read a value from |buffer|, converting to an int assuming little
   // endianness
   static inline uint16_t ReadUint16(const char* buffer) {
-    return *reinterpret_cast<const uint16_t*>(buffer);
+    return base::ByteSwapToLE16(*reinterpret_cast<const uint16_t*>(buffer));
   }
 
   static inline uint32_t ReadUint32(const char* buffer) {
-    return *reinterpret_cast<const uint32_t*>(buffer);
+    return base::ByteSwapToLE32(*reinterpret_cast<const uint32_t*>(buffer));
   }
 
   // |parent| is the decoder that owns us.
