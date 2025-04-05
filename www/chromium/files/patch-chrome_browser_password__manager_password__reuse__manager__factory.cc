--- chrome/browser/password_manager/password_reuse_manager_factory.cc.orig	2025-04-04 08:52:13 UTC
+++ chrome/browser/password_manager/password_reuse_manager_factory.cc
@@ -137,7 +137,7 @@ PasswordReuseManagerFactory::BuildServiceInstanceForBr
   // Prepare password hash data for reuse detection.
   reuse_manager->PreparePasswordHashData(GetSignInStateForMetrics(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordReuseManagerSigninNotifier>
       notifier = std::make_unique<
           password_manager::PasswordReuseManagerSigninNotifierImpl>(
