--- base/cpu.h.orig	2022-12-02 17:56:32 UTC
+++ base/cpu.h
@@ -115,7 +115,7 @@ class BASE_EXPORT CPU final {
   const std::string& cpu_brand() const { return cpu_brand_; }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   enum class CoreType {
     kUnknown = 0,
     kOther,
