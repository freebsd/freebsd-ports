--- src/3rdparty/chromium/ui/gl/gl_implementation.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/gl/gl_implementation.cc
@@ -252,7 +252,7 @@ GetRequestedGLImplementationFromCommandLine(
     const base::CommandLine* command_line) {
   bool overrideUseSoftwareGL =
       command_line->HasSwitch(switches::kOverrideUseSoftwareGLForTests);
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
