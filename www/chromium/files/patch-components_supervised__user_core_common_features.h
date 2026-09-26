--- components/supervised_user/core/common/features.h.orig	2026-09-25 15:26:43 UTC
+++ components/supervised_user/core/common/features.h
@@ -20,7 +20,7 @@ BASE_DECLARE_FEATURE(kLocalWebApprovals);
 BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs;
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
@@ -31,7 +31,7 @@ extern const base::FeatureParam<int> kLocalWebApproval
 BASE_DECLARE_FEATURE(kSupervisedUserVerificationPageOnAndroid);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Uses supervised user strings on the signout dialog.
 BASE_DECLARE_FEATURE(kEnableSupervisedUserVersionSignOutDialog);
 #endif
