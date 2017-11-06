--- gpu/config/gpu_control_list_unittest.cc.orig	2017-04-19 19:06:34 UTC
+++ gpu/config/gpu_control_list_unittest.cc
@@ -175,8 +175,7 @@ TEST_F(GpuControlListTest, VendorOnAllOs
   features = control_list->MakeDecision(
       GpuControlList::kOsLinux, kOsVersion, gpu_info());
   EXPECT_SINGLE_FEATURE(features, TEST_FEATURE_0);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_OPENBSD)
+#if defined(OS_WIN) || (defined(OS_POSIX) && !defined(OS_ANDROID))
   // ControlList entries will be filtered to the current OS only upon loading.
   EXPECT_TRUE(control_list->LoadList(
       vendor_json, GpuControlList::kCurrentOsOnly));
