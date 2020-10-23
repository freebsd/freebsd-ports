--- services/service_manager/sandbox/switches.h.orig	2020-09-21 18:39:22 UTC
+++ services/service_manager/sandbox/switches.h
@@ -55,7 +55,7 @@ SERVICE_MANAGER_SANDBOX_EXPORT extern const char kEnab
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoSandbox[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if defined(OS_WIN)
