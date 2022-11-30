--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -508,7 +508,7 @@ void PasswordsPrivateDelegateImpl::OsReauthCall(
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router)
