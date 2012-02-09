--- content/browser/gpu/gpu_blacklist_unittest.cc.orig	2012-02-01 21:51:33.000000000 +0200
+++ content/browser/gpu/gpu_blacklist_unittest.cc	2012-02-01 21:52:45.000000000 +0200
@@ -191,7 +191,7 @@
   EXPECT_EQ(flags.flags(),
             static_cast<uint32>(GpuFeatureFlags::kGpuFeatureWebgl));
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_OPENBSD)
+    defined(OS_BSD)
   // Blacklist entries will be filtered to the current OS only upon loading.
   EXPECT_TRUE(
       blacklist.LoadGpuBlacklist(vendor_json, GpuBlacklist::kCurrentOsOnly));
