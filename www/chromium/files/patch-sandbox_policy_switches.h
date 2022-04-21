--- sandbox/policy/switches.h.orig	2022-04-21 18:48:31 UTC
+++ sandbox/policy/switches.h
@@ -72,7 +72,8 @@ SANDBOX_POLICY_EXPORT extern const char kDisableSetuid
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SANDBOX_POLICY_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SANDBOX_POLICY_EXPORT extern const char kNoSandbox[];
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+SANDBOX_POLICY_EXPORT extern const char kDisableUnveil[];
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if BUILDFLAG(IS_WIN)
