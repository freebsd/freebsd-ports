--- src/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -643,7 +643,7 @@ void PasswordsPrivateDelegateImpl::OnFet
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
