--- src/3rdparty/chromium/sandbox/policy/switches.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/sandbox/policy/switches.cc
@@ -81,7 +81,7 @@ const char kNoSandbox[] = "no-sandbox";
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
