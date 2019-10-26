--- src/3rdparty/chromium/content/browser/storage_partition_impl_map.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/browser/storage_partition_impl_map.cc
@@ -425,7 +425,7 @@ StoragePartitionImpl* StoragePartitionImplMap::Get(
   bool create_request_context = true;
   if (base::FeatureList::IsEnabled(network::features::kNetworkService)) {
     // These ifdefs should match StoragePartitionImpl::GetURLRequestContext.
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     create_request_context = false;
 #elif defined(OS_ANDROID)
     create_request_context =
