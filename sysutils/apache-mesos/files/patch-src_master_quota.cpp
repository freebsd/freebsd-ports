--- src/master/quota.cpp.orig	2019-10-01 20:10:13 UTC
+++ src/master/quota.cpp
@@ -62,7 +62,7 @@ Try<bool> UpdateQuota::perform(
 
   foreach (const QuotaConfig& config, configs) {
     // Check if there is already quota stored for the role.
-    int configIndex = find_if(
+    int configIndex = std::find_if(
         registryConfigs.begin(),
         registryConfigs.end(),
         [&](const QuotaConfig& registryConfig) {
@@ -91,7 +91,7 @@ Try<bool> UpdateQuota::perform(
     google::protobuf::RepeatedPtrField<Registry::Quota>& quotas =
       *registry->mutable_quotas();
 
-    int quotaIndex = find_if(
+    int quotaIndex = std::find_if(
         quotas.begin(),
         quotas.end(),
         [&](const Registry::Quota& quota) {
