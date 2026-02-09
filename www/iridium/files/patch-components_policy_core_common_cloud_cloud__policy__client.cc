--- components/policy/core/common/cloud/cloud_policy_client.cc.orig	2026-02-16 10:45:29 UTC
+++ components/policy/core/common/cloud/cloud_policy_client.cc
@@ -791,11 +791,11 @@ void CloudPolicyClient::FetchPolicyInternal(
 
   // Build policy fetch requests.
   em::DevicePolicyRequest* policy_request = request->mutable_policy_request();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   em::PolicyFetchRequest* fetch_request = nullptr;
 #endif
   for (const auto& type_to_fetch : types_to_fetch) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     fetch_request = AddPolicyFetchRequest(policy_request, type_to_fetch);
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
