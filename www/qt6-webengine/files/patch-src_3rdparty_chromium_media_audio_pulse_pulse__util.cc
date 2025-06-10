--- src/3rdparty/chromium/media/audio/pulse/pulse_util.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/media/audio/pulse/pulse_util.cc
@@ -50,7 +50,11 @@ constexpr char kBrowserDisplayName[] = "chromium-brows
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
+#endif
 #endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
