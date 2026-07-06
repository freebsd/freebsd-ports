--- gpu/config/gpu_finch_features.cc.orig	2026-06-05 13:45:06 UTC
+++ gpu/config/gpu_finch_features.cc
@@ -110,7 +110,7 @@ const base::FeatureParam<std::string>
 // of associating with an unused IPC::Channel.
 BASE_FEATURE(kRemoveGPULegacyIPC, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to control whether SharedImageStub sequence uses high priority
 // on ChromeOS and Linux. Enabled by default.
 BASE_FEATURE(kSharedImageStubHighPriority, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -119,7 +119,7 @@ BASE_FEATURE(kSharedImageStubHighPriority, base::FEATU
 // Disables hardware YUV conversion on NVIDIA + Wayland to workaround a driver
 // bug.
 BASE_FEATURE(kNvidiaWaylandYuvHardwareConversionWorkaround,
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -470,7 +470,7 @@ BASE_FEATURE(kGPUDriverBugListTestGroup, base::FEATURE
 const base::FeatureParam<int> kGPUDriverBugListTestGroupId{
     &kGPUDriverBugListTestGroup, "test_group", 0};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsForceEnableWebGpuInterop() {
   return base::FeatureList::IsEnabled(kForceEnableWebGpuInterop);
 }
