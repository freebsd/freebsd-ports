--- third_party/WebKit/Source/platform/fonts/FontPlatformData.h.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.h	2017-09-06 21:44:50.459129000 +0200
@@ -48,9 +48,9 @@
 #include "platform/wtf/text/StringImpl.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "platform/fonts/linux/FontRenderStyle.h"
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 OBJC_CLASS NSFont;
@@ -152,7 +152,7 @@
   PassRefPtr<OpenTypeVerticalData> VerticalData() const;
   Vector<char> OpenTypeTable(SkFontTableTag) const;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // The returned styles are all actual styles without
   // FontRenderStyle::NoPreference.
   const FontRenderStyle& GetFontRenderStyle() const { return style_; }
@@ -182,7 +182,7 @@
   FontOrientation orientation_;
 
  private:
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   FontRenderStyle style_;
 #endif
 
