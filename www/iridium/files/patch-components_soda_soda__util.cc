--- components/soda/soda_util.cc.orig	2024-11-04 08:56:03 UTC
+++ components/soda/soda_util.cc
@@ -27,7 +27,7 @@
 #include "base/win/windows_version.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_X86_FAMILY)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_X86_FAMILY)
 #include "base/cpu.h"
 #endif
 
@@ -52,7 +52,7 @@ bool IsSupportedChromeOS() {
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsSupportedLinux() {
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Speech
@@ -83,7 +83,7 @@ bool IsSupportedWin() {
 bool IsOnDeviceSpeechRecognitionSupported() {
 #if BUILDFLAG(IS_CHROMEOS)
   return IsSupportedChromeOS();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsSupportedLinux();
 #elif BUILDFLAG(IS_WIN)
   return IsSupportedWin();
