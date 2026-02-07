--- src/3rdparty/chromium/media/audio/pulse/pulse_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/media/audio/pulse/pulse_util.cc
@@ -50,7 +50,11 @@ static const base::FilePath::CharType kPulseLib[] =
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
+#endif
 #endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
