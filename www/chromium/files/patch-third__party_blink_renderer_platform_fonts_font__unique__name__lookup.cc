--- third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc.orig	2019-02-04 23:35:56.748592000 +0100
+++ third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc	2019-02-04 23:36:16.158548000 +0100
@@ -8,7 +8,7 @@
 
 #if defined(OS_ANDROID)
 #include "third_party/blink/renderer/platform/fonts/android/font_unique_name_lookup_android.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "third_party/blink/renderer/platform/fonts/linux/font_unique_name_lookup_linux.h"
 #endif
 
@@ -21,7 +21,7 @@
 FontUniqueNameLookup::GetPlatformUniqueNameLookup() {
 #if defined(OS_ANDROID)
   return std::make_unique<FontUniqueNameLookupAndroid>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<FontUniqueNameLookupLinux>();
 #else
   NOTREACHED();
