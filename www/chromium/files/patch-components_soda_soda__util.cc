--- components/soda/soda_util.cc.orig	2026-10-22 09:04:01 UTC
+++ components/soda/soda_util.cc
@@ -23,7 +23,7 @@
 #include "base/win/windows_version.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)) && defined(ARCH_CPU_X86_FAMILY)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_FAMILY)
 #include "base/cpu.h"
 #endif
 
@@ -39,7 +39,7 @@ bool IsSupportedChromeOS() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 bool IsSupportedLinux() {
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Speech
@@ -85,7 +85,7 @@ bool IsOnDeviceSpeechRecognitionSupported() {
   // support Gemini Nano.
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_MAC)
   return IsSupportedMac();
