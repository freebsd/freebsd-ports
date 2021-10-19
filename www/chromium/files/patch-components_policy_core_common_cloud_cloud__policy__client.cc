--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2021-09-24 04:26:04 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -405,7 +405,7 @@ void CloudPolicyClient::FetchPolicy() {
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (base::FeatureList::IsEnabled(
