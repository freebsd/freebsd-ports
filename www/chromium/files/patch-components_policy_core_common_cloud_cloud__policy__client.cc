--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2022-02-28 16:54:41 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -419,7 +419,7 @@ void CloudPolicyClient::FetchPolicy() {
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (base::FeatureList::IsEnabled(
