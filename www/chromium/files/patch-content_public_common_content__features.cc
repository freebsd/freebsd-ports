--- content/public/common/content_features.cc.orig	2020-11-13 06:36:43 UTC
+++ content/public/common/content_features.cc
@@ -54,7 +54,7 @@ const base::Feature kAudioServiceLaunchOnStartup{
 const base::Feature kAudioServiceOutOfProcess {
   "AudioServiceOutOfProcess",
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -776,8 +776,8 @@ const base::Feature kWebAssemblyThreads {
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-     defined(OS_MAC)) &&                                             \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
+     defined(OS_MAC)) &&                                                                \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -807,7 +807,7 @@ const base::Feature kWebAuth{"WebAuthentication",
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
