--- src/media/audio/pulse/pulse_util.cc.orig	2026-10-18 18:43:23 UTC
+++ src/media/audio/pulse/pulse_util.cc
@@ -45,8 +45,12 @@ constexpr char kBrowserDisplayName[] = "
 
 #if defined(DLOPEN_PULSEAUDIO)
 static const base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
 #endif
+#endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
   pa_threaded_mainloop_stop(mainloop);
