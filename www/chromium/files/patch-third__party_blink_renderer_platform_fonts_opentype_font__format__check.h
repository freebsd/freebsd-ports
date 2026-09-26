--- third_party/blink/renderer/platform/fonts/opentype/font_format_check.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/blink/renderer/platform/fonts/opentype/font_format_check.h
@@ -5,7 +5,7 @@
 #ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_OPENTYPE_FONT_FORMAT_CHECK_H_
 #define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_OPENTYPE_FONT_FORMAT_CHECK_H_
 
-#include "third_party/blink/renderer/platform/fonts/font_format.h"
+#include "third_party/blink/renderer/platform/fonts/opentype/format_check.rs.h"
 #include "third_party/blink/renderer/platform/platform_export.h"
 #include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"
 #include "third_party/skia/include/core/SkData.h"
@@ -19,7 +19,7 @@ class PLATFORM_EXPORT FontFormatCheck {
 
  public:
   explicit FontFormatCheck(sk_sp<SkData>);
-  virtual ~FontFormatCheck();
+  virtual ~FontFormatCheck() = default;
   virtual bool IsVariableFont() const;
   virtual bool IsCbdtCblcColorFont() const;
   virtual bool IsEbdtEblcMonochromeFont() const;
@@ -46,7 +46,7 @@ class PLATFORM_EXPORT FontFormatCheck {
   enum class COLRVersion { kCOLRV0, kCOLRV1, kNoCOLR };
 
  private:
-  font_format::FontFormatInfo format_info_;
+  rust::Box<font_format_check::FontFormatInfo> format_info_;
 };
 
 }  // namespace blink
