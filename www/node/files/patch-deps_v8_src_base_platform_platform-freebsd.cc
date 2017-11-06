--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2017-10-24 19:40:14 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -51,6 +51,48 @@ void* OS::Allocate(const size_t requested, size_t* all
   return mbase;
 }
 
+#ifdef __arm__
+
+bool OS::ArmUsingHardFloat() {
+  // GCC versions 4.6 and above define __ARM_PCS or __ARM_PCS_VFP to specify
+  // the Floating Point ABI used (PCS stands for Procedure Call Standard).
+  // We use these as well as a couple of other defines to statically determine
+  // what FP ABI used.
+  // GCC versions 4.4 and below don't support hard-fp.
+  // GCC versions 4.5 may support hard-fp without defining __ARM_PCS or
+  // __ARM_PCS_VFP.
+
+#define GCC_VERSION (__GNUC__ * 10000                                          \
+                     + __GNUC_MINOR__ * 100                                    \
+                     + __GNUC_PATCHLEVEL__)
+#if GCC_VERSION >= 40600
+#if defined(__ARM_PCS_VFP)
+  return true;
+#else
+  return false;
+#endif
+
+#elif GCC_VERSION < 40500
+  return false;
+
+#else
+#if defined(__ARM_PCS_VFP)
+  return true;
+#elif defined(__ARM_PCS) || defined(__SOFTFP__) || defined(__SOFTFP) || \
+      !defined(__VFP_FP__)
+  return false;
+#else
+#error "Your version of GCC does not report the FP ABI compiled for."          \
+       "Please report it on this issue"                                        \
+       "http://code.google.com/p/v8/issues/detail?id=2140"
+
+#endif
+#endif
+#undef GCC_VERSION
+}
+
+#endif  // def __arm__
+
 
 static unsigned StringToLong(char* buffer) {
   return static_cast<unsigned>(strtol(buffer, NULL, 16));  // NOLINT
