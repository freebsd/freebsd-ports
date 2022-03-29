--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2022-03-25 21:59:56 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -417,7 +417,7 @@ void CloudPolicyClient::FetchPolicy() {
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (base::FeatureList::IsEnabled(
