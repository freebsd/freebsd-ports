--- sandbox/policy/switches.cc.orig	2024-11-14 07:57:23 UTC
+++ sandbox/policy/switches.cc
@@ -55,10 +55,10 @@ const char kWindowsSystemProxyResolverSandbox[] = "pro
 const char kMirroringSandbox[] = "mirroring";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 const char kHardwareVideoDecodingSandbox[] = "hardware_video_decoding";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kHardwareVideoEncodingSandbox[] = "hardware_video_encoding";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -71,7 +71,7 @@ const char kLibassistantSandbox[] = "libassistant";
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
@@ -102,7 +102,9 @@ const char kGpuSandboxFailuresFatal[] = "gpu-sandbox-f
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+const char kDisableUnveil[] = "disable-unveil";
+
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
