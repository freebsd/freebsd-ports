--- third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc.orig	2021-09-14 01:52:03 UTC
+++ third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc
@@ -7,7 +7,7 @@
 #if defined(OS_ANDROID)
 #include "third_party/blink/public/mojom/font_unique_name_lookup/font_unique_name_lookup.mojom-blink.h"
 #include "third_party/blink/renderer/platform/fonts/android/font_unique_name_lookup_android.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "third_party/blink/renderer/platform/fonts/linux/font_unique_name_lookup_linux.h"
 #elif defined(OS_WIN)
 #include "third_party/blink/renderer/platform/fonts/win/font_unique_name_lookup_win.h"
@@ -22,7 +22,7 @@ std::unique_ptr<FontUniqueNameLookup>
 FontUniqueNameLookup::GetPlatformUniqueNameLookup() {
 #if defined(OS_ANDROID)
   return std::make_unique<FontUniqueNameLookupAndroid>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<FontUniqueNameLookupLinux>();
 #elif defined(OS_WIN)
   return std::make_unique<FontUniqueNameLookupWin>();
