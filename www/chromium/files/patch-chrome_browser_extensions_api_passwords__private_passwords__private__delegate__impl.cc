--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -631,7 +631,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
