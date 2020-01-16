--- content/public/common/content_features.cc.orig	2019-12-16 21:51:26 UTC
+++ content/public/common/content_features.cc
@@ -53,7 +53,7 @@ const base::Feature kAudioServiceLaunchOnStartup{
 const base::Feature kAudioServiceOutOfProcess{
   "AudioServiceOutOfProcess",
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -628,7 +628,7 @@ const base::Feature kWebAssemblyThreads {
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)) && \
+#if (defined(OS_BSD) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)) && \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -663,7 +663,7 @@ const base::Feature kWebAuthBle{"WebAuthenticationBle"
 // https://w3c.github.io/webauthn
 const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
-#if !defined(OS_CHROMEOS) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(OS_LINUX)) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
