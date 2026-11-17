--- src/ui/gl/gl_implementation.cc.orig	2026-10-18 18:43:23 UTC
+++ src/ui/gl/gl_implementation.cc
@@ -331,7 +331,7 @@ GetRequestedGLImplementationFromCommandL
     const base::CommandLine* command_line) {
   bool overrideUseSoftwareGL =
       command_line->HasSwitch(switches::kOverrideUseSoftwareGLForTests);
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
