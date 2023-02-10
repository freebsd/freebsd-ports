--- src/3rdparty/chromium/ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -102,7 +102,7 @@ class OzonePlatformHeadless : public OzonePlatform {
   }
 
 // Desktop Linux, not ChromeOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
     !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_CHROMECAST)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
