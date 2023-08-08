--- src/3rdparty/chromium/base/cpu.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/cpu.h
@@ -115,7 +115,7 @@ class BASE_EXPORT CPU final {
   const std::string& cpu_brand() const { return cpu_brand_; }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   enum class CoreType {
     kUnknown = 0,
     kOther,
