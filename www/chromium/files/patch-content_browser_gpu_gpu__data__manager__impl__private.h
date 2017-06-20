--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2017-06-05 19:03:07 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -153,7 +153,7 @@ class CONTENT_EXPORT GpuDataManagerImplPrivate {
                            UnblockOtherDomainFrom3DAPIs);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            UnblockThisDomainFrom3DAPIs);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            SetGLStrings);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
