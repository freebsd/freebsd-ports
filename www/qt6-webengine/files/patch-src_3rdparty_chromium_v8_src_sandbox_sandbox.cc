--- src/3rdparty/chromium/v8/src/sandbox/sandbox.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/v8/src/sandbox/sandbox.cc
@@ -46,7 +46,7 @@ static Address DetermineAddressSpaceLimit() {
   }
 #endif  // V8_TARGET_ARCH_X64
 
-#if defined(V8_TARGET_ARCH_ARM64) && defined(V8_TARGET_OS_ANDROID)
+#if defined(V8_TARGET_ARCH_ARM64) && (defined(V8_TARGET_OS_ANDROID) || defined(V8_TARGET_OS_OPENBSD))
   // On Arm64 Android assume a 40-bit virtual address space (39 bits for
   // userspace and kernel each) as that appears to be the most common
   // configuration and there seems to be no easy way to retrieve the actual
