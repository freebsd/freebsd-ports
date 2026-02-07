--- components/policy/core/common/cloud/cloud_policy_refresh_scheduler.cc.orig	2025-12-06 13:30:52 UTC
+++ components/policy/core/common/cloud/cloud_policy_refresh_scheduler.cc
@@ -26,7 +26,7 @@ namespace policy {
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRetryWithKeyReset, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
@@ -219,7 +219,7 @@ void CloudPolicyRefreshScheduler::OnStoreError(CloudPo
   // continue using the stale information. Thus, no specific response to a store
   // error is required. NB: Changes to is_managed fire OnStoreLoaded().
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Client is registered means we have successfully get policy key once. However,
   // a following policy fetch request is failed because we can't verified
   // signature. Delete the policy key so that we can get it again with next
