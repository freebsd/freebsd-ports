--- components/safe_browsing/core/common/features.cc.orig	2021-09-24 18:43:25 UTC
+++ components/safe_browsing/core/common/features.cc
@@ -113,7 +113,7 @@ const base::Feature
 
 const base::Feature kSafeBrowsingSeparateNetworkContexts {
   "SafeBrowsingSeparateNetworkContexts",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -122,7 +122,7 @@ const base::Feature kSafeBrowsingSeparateNetworkContex
 
 const base::Feature kSafeBrowsingRemoveCookies {
   "SafeBrowsingRemoveCookies",
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
