--- components/supervised_user/core/common/features.cc.orig	2025-11-01 06:40:37 UTC
+++ components/supervised_user/core/common/features.cc
@@ -32,7 +32,7 @@ BASE_FEATURE(kAllowSubframeLocalWebApprovals,
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -41,7 +41,7 @@ const base::FeatureParam<int> kLocalWebApprovalBottomS
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableLocalWebApprovalErrorDialog,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
@@ -53,7 +53,7 @@ BASE_FEATURE(kLocalWebApprovalsWidgetSupportsUrlPayloa
 // TODO(crbug.com/435635774): Release the interstitial v3 in all platforms.
 BASE_FEATURE(kSupervisedUserBlockInterstitialV3,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -89,7 +89,7 @@ bool IsLocalWebApprovalsEnabledForSubframes() {
   return base::FeatureList::IsEnabled(kAllowSubframeLocalWebApprovals);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
