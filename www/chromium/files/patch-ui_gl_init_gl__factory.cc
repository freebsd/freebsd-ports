--- ui/gl/init/gl_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/gl/init/gl_factory.cc
@@ -171,7 +171,7 @@ bool InitializeGLOneOffPlatformHelper(bool init_extens
 }  // namespace
 
 GLImplementationParts GetSoftwareGLImplementationForPlatform() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetSoftwareGLImplementation();
 #else
   return GetLegacySoftwareGLImplementation();
