--- ui/ozone/platform/headless/ozone_platform_headless.cc.orig	2025-05-05 10:57:53 UTC
+++ ui/ozone/platform/headless/ozone_platform_headless.cc
@@ -108,7 +108,7 @@ class OzonePlatformHeadlessImpl : public OzonePlatform
   }
 
 // Desktop Linux, not CastOS.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   const PlatformProperties& GetPlatformProperties() override {
     static base::NoDestructor<OzonePlatform::PlatformProperties> properties;
     static bool initialized = false;
