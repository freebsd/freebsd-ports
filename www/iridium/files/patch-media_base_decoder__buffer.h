--- media/base/decoder_buffer.h.orig	2018-04-28 17:47:57.057477000 +0200
+++ media/base/decoder_buffer.h	2018-04-28 17:48:11.847624000 +0200
@@ -37,7 +37,7 @@
     : public base::RefCountedThreadSafe<DecoderBuffer> {
  public:
   enum {
-    kPaddingSize = 32,
+    kPaddingSize = 64,
 #if defined(ARCH_CPU_ARM_FAMILY)
     kAlignmentSize = 16
 #else
