--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -43,7 +43,7 @@ const base::Feature kAudioServiceLaunchOnStartup{
 // Runs the audio service in a separate process.
 const base::Feature kAudioServiceOutOfProcess{
   "AudioServiceOutOfProcess",
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -618,7 +618,7 @@ const base::Feature kWebAssemblyThreads {
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)) && \
+#if (defined(OS_BSD) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)) && \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -653,7 +653,7 @@ const base::Feature kWebAuthBle{"WebAuthenticationBle"
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
