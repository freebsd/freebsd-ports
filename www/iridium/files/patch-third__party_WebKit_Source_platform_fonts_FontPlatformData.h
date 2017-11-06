--- third_party/WebKit/Source/platform/fonts/FontPlatformData.h.orig	2017-04-19 19:06:50 UTC
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.h
@@ -47,9 +47,9 @@
 #include "wtf/text/CString.h"
 #include "wtf/text/StringImpl.h"
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 #include "platform/fonts/linux/FontRenderStyle.h"
-#endif  // OS(LINUX) || OS(ANDROID)
+#endif  // OS(LINUX) || OS(ANDROID) || OS(BSD)
 
 #if OS(MACOSX)
 OBJC_CLASS NSFont;
@@ -151,7 +151,7 @@ class PLATFORM_EXPORT FontPlatformData {
   PassRefPtr<OpenTypeVerticalData> verticalData() const;
   PassRefPtr<SharedBuffer> openTypeTable(SkFontTableTag) const;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   // The returned styles are all actual styles without
   // FontRenderStyle::NoPreference.
   const FontRenderStyle& getFontRenderStyle() const { return m_style; }
@@ -179,7 +179,7 @@ class PLATFORM_EXPORT FontPlatformData {
   FontOrientation m_orientation;
 
  private:
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   FontRenderStyle m_style;
 #endif
 
