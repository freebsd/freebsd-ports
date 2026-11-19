--- components/supervised_user/core/common/pref_names.h.orig	2026-11-19 12:25:27 UTC
+++ components/supervised_user/core/common/pref_names.h
@@ -118,7 +118,7 @@ inline constexpr char kDefaultSupervisedUserFilteringB
     "profile.managed.default_filtering_behavior";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.
