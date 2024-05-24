--- components/soda/soda_util.cc.orig	2024-05-21 18:07:39 UTC
+++ components/soda/soda_util.cc
@@ -35,7 +35,7 @@ bool IsOnDeviceSpeechRecognitionSupported() {
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check if the CPU has the required instruction set to run the Speech
   // On-Device API (SODA) library.
   static bool has_sse41 = base::CPU().has_sse41();
