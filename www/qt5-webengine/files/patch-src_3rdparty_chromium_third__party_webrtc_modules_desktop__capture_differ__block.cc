--- src/3rdparty/chromium/third_party/webrtc/modules/desktop_capture/differ_block.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/desktop_capture/differ_block.cc
@@ -30,11 +30,7 @@ bool VectorDifference(const uint8_t* image1, const uin
   static bool (*diff_proc)(const uint8_t*, const uint8_t*) = nullptr;
 
   if (!diff_proc) {
-#if defined(WEBRTC_ARCH_ARM_FAMILY) || defined(WEBRTC_ARCH_MIPS_FAMILY)
-    // For ARM and MIPS processors, always use C version.
-    // TODO(hclam): Implement a NEON version.
-    diff_proc = &VectorDifference_C;
-#else
+#if defined(WEBRTC_ARCH_X86_FAMILY)
     bool have_sse2 = WebRtc_GetCPUInfo(kSSE2) != 0;
     // For x86 processors, check if SSE2 is supported.
     if (have_sse2 && kBlockSize == 32) {
@@ -44,6 +40,10 @@ bool VectorDifference(const uint8_t* image1, const uin
     } else {
       diff_proc = &VectorDifference_C;
     }
+#else
+    // For other processors, always use C version.
+    // TODO(hclam): Implement a NEON version.
+    diff_proc = &VectorDifference_C;
 #endif
   }
 
