Enable FLAC on platforms without ffvpx like powerpc*

--- dom/media/flac/FlacDecoder.cpp.orig	2021-04-15 19:44:28 UTC
+++ dom/media/flac/FlacDecoder.cpp
@@ -7,6 +7,7 @@
 #include "FlacDecoder.h"
 #include "MediaContainerType.h"
 #include "mozilla/StaticPrefs_media.h"
+#include "PDMFactory.h"
 
 namespace mozilla {
 
@@ -14,6 +15,10 @@ namespace mozilla {
 bool FlacDecoder::IsEnabled() {
 #ifdef MOZ_FFVPX
   return StaticPrefs::media_flac_enabled();
+#elif defined(MOZ_FFMPEG)
+  RefPtr<PDMFactory> platform = new PDMFactory();
+  return StaticPrefs::media_flac_enabled() &&
+         platform->SupportsMimeType("audio/flac"_ns);
 #else
   return false;
 #endif
