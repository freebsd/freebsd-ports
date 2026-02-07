--- src/3rdparty/chromium/sandbox/policy/switches.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/sandbox/policy/switches.cc
@@ -38,7 +38,9 @@ const char kNoSandbox[] = "no-sandbox";
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+const char kDisableUnveil[] = "disable-unveil";
+
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
