--- services/service_manager/sandbox/switches.cc.orig	2020-09-21 18:39:22 UTC
+++ services/service_manager/sandbox/switches.cc
@@ -85,7 +85,7 @@ const char kGpuSandboxFailuresFatal[] = "gpu-sandbox-f
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
