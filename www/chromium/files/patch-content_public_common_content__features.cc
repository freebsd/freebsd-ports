--- content/public/common/content_features.cc.orig	2022-02-07 13:39:41 UTC
+++ content/public/common/content_features.cc
@@ -50,7 +50,7 @@ const base::Feature kAudioServiceOutOfProcess {
   "AudioServiceOutOfProcess",
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -62,7 +62,7 @@ const base::Feature kAudioServiceOutOfProcess {
 // kAudioServiceOutOfProcess feature is enabled.
 const base::Feature kAudioServiceSandbox {
   "AudioServiceSandbox",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_FUCHSIA)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -973,7 +973,7 @@ const base::Feature kWebAssemblyBaseline{"WebAssemblyB
 const base::Feature kWebAssemblyCodeProtection{
     "WebAssemblyCodeProtection", base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 // Use memory protection keys in userspace (PKU) (if available) to protect code
 // JITed for WebAssembly. Fall back to traditional memory protection if
 // WebAssemblyCodeProtection is also enabled.
@@ -1003,7 +1003,7 @@ const base::Feature kWebAssemblyTiering{"WebAssemblyTi
 const base::Feature kWebAssemblyTrapHandler {
   "WebAssemblyTrapHandler",
 #if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-      defined(OS_MAC)) &&                                             \
+      defined(OS_MAC) || defined(OS_BSD)) &&                          \
      defined(ARCH_CPU_X86_64)) ||                                     \
     (defined(OS_MAC) && defined(ARCH_CPU_ARM64))
       base::FEATURE_ENABLED_BY_DEFAULT
@@ -1025,7 +1025,7 @@ const base::Feature kWebAuthCable {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 // If updating this, also update kWebAuthCableServerLink.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
@@ -1093,7 +1093,11 @@ const base::Feature kWebUIReportOnlyTrustedTypes{
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if defined(OS_BSD)
+const base::Feature kWebUsb{"WebUSB", base::FEATURE_DISABLED_BY_DEFAULT};
+#else
 const base::Feature kWebUsb{"WebUSB", base::FEATURE_ENABLED_BY_DEFAULT};
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 const base::Feature kWebXr{"WebXR", base::FEATURE_ENABLED_BY_DEFAULT};
@@ -1193,7 +1197,7 @@ const base::Feature kRetryGetVideoCaptureDeviceInfos{
 
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // If the JavaScript on a WebUI page has an error (such as an unhandled
 // exception), report that error back the crash reporting infrastructure, same
 // as we do for program crashes.
