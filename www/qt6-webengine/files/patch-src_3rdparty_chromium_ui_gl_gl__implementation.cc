--- src/3rdparty/chromium/ui/gl/gl_implementation.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/ui/gl/gl_implementation.cc
@@ -286,7 +286,7 @@ GetRequestedGLImplementationFromCommandLine(
   *fallback_to_software_gl = false;
   bool overrideUseSoftwareGL =
       command_line->HasSwitch(switches::kOverrideUseSoftwareGLForTests);
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
