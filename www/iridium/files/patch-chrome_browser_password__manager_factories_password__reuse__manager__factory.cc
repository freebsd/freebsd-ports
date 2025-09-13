--- chrome/browser/password_manager/factories/password_reuse_manager_factory.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/password_manager/factories/password_reuse_manager_factory.cc
@@ -128,7 +128,7 @@ PasswordReuseManagerFactory::BuildServiceInstanceForBr
   // Prepare password hash data for reuse detection.
   reuse_manager->PreparePasswordHashData(GetSignInStateForMetrics(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<password_manager::PasswordReuseManagerSigninNotifier>
       notifier = std::make_unique<
           password_manager::PasswordReuseManagerSigninNotifierImpl>(
