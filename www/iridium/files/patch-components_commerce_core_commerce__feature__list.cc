--- components/commerce/core/commerce_feature_list.cc.orig	2024-08-27 06:28:16 UTC
+++ components/commerce/core/commerce_feature_list.cc
@@ -168,7 +168,7 @@ BASE_FEATURE(kPriceInsights,
              "PriceInsights",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPriceInsightsRegionLaunched,
              "PriceInsightsRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -261,7 +261,7 @@ const base::FeatureParam<bool> kDeleteAllMerchantsOnCl
 
 BASE_FEATURE(kShoppingList, "ShoppingList", base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShoppingListRegionLaunched,
              "ShoppingListRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
