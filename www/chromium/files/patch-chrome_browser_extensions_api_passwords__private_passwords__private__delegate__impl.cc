--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -642,7 +642,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
