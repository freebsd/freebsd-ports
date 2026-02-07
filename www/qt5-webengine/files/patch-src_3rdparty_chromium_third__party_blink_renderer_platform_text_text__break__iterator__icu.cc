--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator_icu.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator_icu.cc
@@ -119,11 +119,11 @@ enum TextContext { kNoContext, kPriorContext, kPrimary
 
 const int kTextBufferCapacity = 16;
 
-typedef struct {
+struct UTextWithBuffer {
   DISALLOW_NEW();
   UText text;
   UChar buffer[kTextBufferCapacity];
-} UTextWithBuffer;
+};
 
 static inline int64_t TextPinIndex(int64_t& index, int64_t limit) {
   if (index < 0)
