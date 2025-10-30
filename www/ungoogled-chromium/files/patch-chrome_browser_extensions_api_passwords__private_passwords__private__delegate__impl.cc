--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -660,7 +660,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
