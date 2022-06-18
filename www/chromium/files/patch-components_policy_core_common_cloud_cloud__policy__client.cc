--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2022-06-17 14:20:10 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -447,7 +447,7 @@ void CloudPolicyClient::FetchPolicy() {
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.first ==
