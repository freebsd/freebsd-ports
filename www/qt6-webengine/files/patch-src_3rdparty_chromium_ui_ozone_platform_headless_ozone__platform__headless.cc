--- src/3rdparty/chromium/ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2022-07-22 17:30:31 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -102,7 +102,7 @@ class OzonePlatformHeadless : public OzonePlatform {
   }
 
 // Desktop Linux, not CastOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
     static bool initialized = false;
