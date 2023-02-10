--- ui/gl/gl_features.h.orig	2023-01-17 19:19:00 UTC
+++ ui/gl/gl_features.h
@@ -23,7 +23,7 @@ GL_EXPORT BASE_DECLARE_FEATURE(kAndroidFrameDeadline);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||     \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #define PASSTHROUGH_COMMAND_DECODER_LAUNCHED
 #else
 // All features in alphabetical order. The features should be documented
