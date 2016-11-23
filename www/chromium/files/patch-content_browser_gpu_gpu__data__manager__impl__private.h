--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/gpu/gpu_data_manager_impl_private.h	2016-08-18 02:42:16.971805000 +0300
@@ -154,7 +154,7 @@
                            UnblockOtherDomainFrom3DAPIs);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            UnblockThisDomainFrom3DAPIs);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
                            SetGLStrings);
   FRIEND_TEST_ALL_PREFIXES(GpuDataManagerImplPrivateTest,
