https://chromium.googlesource.com/chromium/src/+/a568ded46a67%5E%21/

--- media/base/decoder_buffer.h.orig	2018-03-20 22:05:27 UTC
+++ media/base/decoder_buffer.h
@@ -37,7 +37,7 @@ class MEDIA_EXPORT DecoderBuffer
     : public base::RefCountedThreadSafe<DecoderBuffer> {
  public:
   enum {
-    kPaddingSize = 32,
+    kPaddingSize = 64,
 #if defined(ARCH_CPU_ARM_FAMILY)
     kAlignmentSize = 16
 #else
