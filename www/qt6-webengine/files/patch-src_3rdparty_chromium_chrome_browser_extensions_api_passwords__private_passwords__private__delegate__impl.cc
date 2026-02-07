--- src/3rdparty/chromium/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -634,7 +634,7 @@ void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
