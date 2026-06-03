--- src/3rdparty/chromium/components/supervised_user/core/common/features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/components/supervised_user/core/common/features.cc
@@ -37,7 +37,7 @@ BASE_FEATURE(kAllowSubframeLocalWebApprovals,
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -46,7 +46,7 @@ const base::FeatureParam<int> kLocalWebApprovalBottomS
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableLocalWebApprovalErrorDialog,
              "EnableLocalWebApprovalErrorDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -58,7 +58,7 @@ BASE_FEATURE(kLocalWebApprovalsWidgetSupportsUrlPayloa
 
 // TODO(crbug.com/435635774): Release the interstitial v3 in all platforms.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSupervisedUserBlockInterstitialV3,
              "SupervisedUserBlockInterstitialV3",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -98,7 +98,7 @@ bool IsLocalWebApprovalsEnabledForSubframes() {
   return base::FeatureList::IsEnabled(kAllowSubframeLocalWebApprovals);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              "EnableSupervisedUserVersionSignOutDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
