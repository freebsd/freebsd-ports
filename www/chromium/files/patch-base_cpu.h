--- base/cpu.h.orig	2022-02-07 13:39:41 UTC
+++ base/cpu.h
@@ -104,7 +104,7 @@ class BASE_EXPORT CPU final {
   const std::string& cpu_brand() const { return cpu_brand_; }
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   enum class CoreType {
     kUnknown = 0,
     kOther,
