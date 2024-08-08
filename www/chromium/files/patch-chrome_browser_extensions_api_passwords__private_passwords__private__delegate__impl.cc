--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2024-07-30 11:12:21 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -611,7 +611,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
