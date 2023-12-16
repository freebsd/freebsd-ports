--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -601,7 +601,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
