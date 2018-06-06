--- src/3rdparty/chromium/v8/src/base/platform/platform-freebsd.cc.orig	2017-09-25 11:52:56 UTC
+++ src/3rdparty/chromium/v8/src/base/platform/platform-freebsd.cc
@@ -36,6 +36,22 @@ namespace v8 {
 namespace base {
 
 
+#ifdef __arm__
+bool OS::ArmUsingHardFloat() {
+#if defined(__ARM_PCS_VFP)
+  return true;
+#elif defined(__ARM_PCS) || defined(__SOFTFP__) || defined(__SOFTFP) || \
+      !defined(__VFP_FP__)
+  return false;
+#else
+#error "Your compiler does not report the FP ABI compiled for."         \
+       "Please report it on this issue"                                 \
+       "http://code.google.com/p/v8/issues/detail?id=2140"
+#endif
+}
+#endif
+
+
 const char* OS::LocalTimezone(double time, TimezoneCache* cache) {
   if (std::isnan(time)) return "";
   time_t tv = static_cast<time_t>(std::floor(time/msPerSecond));
