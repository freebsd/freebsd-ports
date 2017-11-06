--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2017-04-19 19:06:33 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -156,7 +156,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
                            UnblockOtherDomainFrom3DAPIs);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            UnblockThisDomainFrom3DAPIs);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            SetGLStrings);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
