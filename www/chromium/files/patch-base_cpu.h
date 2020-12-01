--- base/cpu.h.orig	2020-11-16 17:24:49 UTC
+++ base/cpu.h
@@ -73,7 +73,7 @@ class BASE_EXPORT CPU final {
   IntelMicroArchitecture GetIntelMicroArchitecture() const;
   const std::string& cpu_brand() const { return cpu_brand_; }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
   enum class CoreType {
     kUnknown = 0,
@@ -124,7 +124,7 @@ class BASE_EXPORT CPU final {
   // cpuidle driver.
   using CoreIdleTimes = std::vector<TimeDelta>;
   static bool GetCumulativeCoreIdleTimes(CoreIdleTimes&);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
         // defined(OS_AIX)
 
  private:
