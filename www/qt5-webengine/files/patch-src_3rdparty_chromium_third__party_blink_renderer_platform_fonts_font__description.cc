--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_description.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_description.cc
@@ -38,7 +38,7 @@
 #include "third_party/blink/renderer/platform/wtf/text/atomic_string_hash.h"
 #include "third_party/blink/renderer/platform/wtf/text/string_hash.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -223,7 +223,7 @@ FontCacheKey FontDescription::CacheKey(
       static_cast<unsigned>(fields_.orientation_) << 1 |       // bit 2-3
       static_cast<unsigned>(fields_.subpixel_text_position_);  // bit 1
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   float device_scale_factor_for_key = FontCache::DeviceScaleFactor();
 #else
   float device_scale_factor_for_key = 1.0f;
