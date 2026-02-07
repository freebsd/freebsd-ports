--- src/3rdparty/chromium/content/public/common/content_features.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/public/common/content_features.cc
@@ -55,7 +55,7 @@ const base::Feature kAudioServiceOutOfProcess {
 const base::Feature kAudioServiceOutOfProcess {
   "AudioServiceOutOfProcess",
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -787,8 +787,8 @@ const base::Feature kWebAssemblyThreads {
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-     defined(OS_MAC)) &&                                             \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
+     defined(OS_MAC)) &&                                                                \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -818,7 +818,7 @@ const base::Feature kWebAuthCable {
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
