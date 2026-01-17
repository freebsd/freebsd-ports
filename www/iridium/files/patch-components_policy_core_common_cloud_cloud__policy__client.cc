--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2026-01-16 14:21:21 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -779,7 +779,7 @@ void CloudPolicyClient::FetchPolicy(PolicyFetchReason 
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.policy_type() ==
