--- components/policy/core/common/cloud/cloud_policy_refresh_scheduler.cc.orig	2025-11-01 06:40:37 UTC
+++ components/policy/core/common/cloud/cloud_policy_refresh_scheduler.cc
@@ -25,7 +25,7 @@ namespace policy {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRetryWithKeyReset, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
@@ -218,7 +218,7 @@ void CloudPolicyRefreshScheduler::OnStoreError(CloudPo
   // continue using the stale information. Thus, no specific response to a store
   // error is required. NB: Changes to is_managed fire OnStoreLoaded().
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Client is registered means we have successfully get policy key once. However,
   // a following policy fetch request is failed because we can't verified
   // signature. Delete the policy key so that we can get it again with next
