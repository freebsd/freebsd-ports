--- chrome/test/supervised_user/google_auth_state_waiter_mixin.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/test/supervised_user/google_auth_state_waiter_mixin.cc
@@ -23,7 +23,7 @@ GoogleAuthStateWaiterMixin::GoogleAuthStateWaiterMixin
 GoogleAuthStateWaiterMixin::~GoogleAuthStateWaiterMixin() = default;
 
 void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ChildAccountService* child_account_service =
       ChildAccountServiceFactory::GetForProfile(
           test_base_->browser()->GetProfile());
