--- sandbox/policy/switches.cc.orig	2022-02-07 13:39:41 UTC
+++ sandbox/policy/switches.cc
@@ -94,7 +94,9 @@ const char kGpuSandboxFailuresFatal[] = "gpu-sandbox-f
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+const char kDisableUnveil[] = "disable-unveil";
+
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
