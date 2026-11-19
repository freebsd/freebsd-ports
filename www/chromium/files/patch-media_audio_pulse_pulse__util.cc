--- media/audio/pulse/pulse_util.cc.orig	2026-11-19 12:25:27 UTC
+++ media/audio/pulse/pulse_util.cc
@@ -43,7 +43,11 @@ constexpr char kBrowserDisplayName[] = "chromium-brows
 
 #if defined(DLOPEN_PULSEAUDIO)
 constexpr base::FilePath::CharType kPulseLib[] =
+#if BUILDFLAG(IS_BSD)
+    FILE_PATH_LITERAL("libpulse.so");
+#else
     FILE_PATH_LITERAL("libpulse.so.0");
+#endif
 #endif
 
 void DestroyMainloop(pa_threaded_mainloop* mainloop) {
