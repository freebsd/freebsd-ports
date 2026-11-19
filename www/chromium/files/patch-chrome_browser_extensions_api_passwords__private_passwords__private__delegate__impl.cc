--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -606,7 +606,7 @@ void PasswordsPrivateDelegateImpl::OnFetchingFamilyMem
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
