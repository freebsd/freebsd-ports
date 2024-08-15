--- chrome/enterprise_companion/lock.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/enterprise_companion/lock.cc
@@ -16,7 +16,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLockName[] = "/ChromeEnterpriseCompanion.lock";
 #elif BUILDFLAG(IS_MAC)
 constexpr char kLockName[] = "org.chromium.ChromeEnterpriseCompanion.lock";
@@ -41,7 +41,7 @@ CSecurityDesc GetAdminDaclSecurityDescriptor() {
 namespace enterprise_companion {
 
 std::unique_ptr<ScopedLock> CreateScopedLock() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return named_system_lock::ScopedLock::Create(kLockName, base::Seconds(0));
 #elif BUILDFLAG(IS_WIN)
   CSecurityAttributes sa =
