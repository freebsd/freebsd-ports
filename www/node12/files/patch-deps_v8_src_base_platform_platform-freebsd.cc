--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2020-01-07 22:07:49 UTC
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -81,8 +81,8 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
-              lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
-              reinterpret_cast<uintptr_t>(map->kve_end)));
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
         }
 
         start += ssize;
@@ -93,6 +93,48 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
 }
 
 void OS::SignalCodeMovingGC() {}
+
+#ifdef __arm__
+
+bool OS::ArmUsingHardFloat() {
+// GCC versions 4.6 and above define __ARM_PCS or __ARM_PCS_VFP to specify
+// the Floating Point ABI used (PCS stands for Procedure Call Standard).
+// We use these as well as a couple of other defines to statically determine
+// what FP ABI used.
+// GCC versions 4.4 and below don't support hard-fp.
+// GCC versions 4.5 may support hard-fp without defining __ARM_PCS or
+// __ARM_PCS_VFP.
+
+#define GCC_VERSION \
+  (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
+#if GCC_VERSION >= 40600 && !defined(__clang__)
+#if defined(__ARM_PCS_VFP)
+  return true;
+#else
+  return false;
+#endif
+
+#elif GCC_VERSION < 40500 && !defined(__clang__)
+  return false;
+
+#else
+#if defined(__ARM_PCS_VFP)
+  return true;
+#elif defined(__ARM_PCS) || defined(__SOFTFP__) || defined(__SOFTFP) || \
+    !defined(__VFP_FP__)
+  return false;
+#else
+#error \
+    "Your version of compiler does not report the FP ABI compiled for."     \
+       "Please report it on this issue"                                        \
+       "http://code.google.com/p/v8/issues/detail?id=2140"
+
+#endif
+#endif
+#undef GCC_VERSION
+}
+
+#endif // def __arm__
 
 void OS::AdjustSchedulingParams() {}
 
