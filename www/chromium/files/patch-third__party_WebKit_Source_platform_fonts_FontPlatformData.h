--- third_party/WebKit/Source/platform/fonts/FontPlatformData.h.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.h
@@ -47,9 +47,9 @@
 #include "platform/wtf/text/StringImpl.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include "platform/fonts/linux/FontRenderStyle.h"
-#endif  // OS(LINUX) || OS(ANDROID)
+#endif  // OS(LINUX) || OS(ANDROID) || OS(BSD)
 
 #if OS(MACOSX)
 OBJC_CLASS NSFont;
@@ -147,7 +147,7 @@ class PLATFORM_EXPORT FontPlatformData {
   PassRefPtr<OpenTypeVerticalData> VerticalData() const;
   PassRefPtr<SharedBuffer> OpenTypeTable(SkFontTableTag) const;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   // The returned styles are all actual styles without
   // FontRenderStyle::NoPreference.
   const FontRenderStyle& GetFontRenderStyle() const { return style_; }
@@ -177,7 +177,7 @@ class PLATFORM_EXPORT FontPlatformData {
   FontOrientation orientation_;
 
  private:
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   FontRenderStyle style_;
 #endif
 
