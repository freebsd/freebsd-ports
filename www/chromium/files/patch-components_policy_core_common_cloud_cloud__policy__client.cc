--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2024-11-14 07:57:23 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -720,7 +720,7 @@ void CloudPolicyClient::FetchPolicy(PolicyFetchReason 
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.first ==
