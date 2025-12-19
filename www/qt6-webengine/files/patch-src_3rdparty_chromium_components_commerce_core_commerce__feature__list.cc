--- src/3rdparty/chromium/components/commerce/core/commerce_feature_list.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/commerce/core/commerce_feature_list.cc
@@ -157,7 +157,7 @@ BASE_FEATURE(kPriceInsights,
              "PriceInsights",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPriceInsightsRegionLaunched,
              "PriceInsightsRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -218,7 +218,7 @@ const char kDiscountOnShoppyPageParam[] = "discount-on
 const char kDiscountOnShoppyPageParam[] = "discount-on-shoppy-page";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::FeatureParam<bool> kDiscountOnShoppyPage{
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, true};
 #else
@@ -227,7 +227,7 @@ const base::FeatureParam<bool> kDiscountOnShoppyPage{
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDiscountInfoApiRegionLaunched,
              "EnableDiscountInfoApiRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -242,7 +242,7 @@ const char kNonMerchantWideBehaviorParam[] = "non-merc
 const char kNonMerchantWideBehaviorParam[] = "non-merchant-wide-behavior";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDiscountDialogAutoPopupBehaviorSetting,
              "DiscountDialogAutoPopupBehaviorSetting",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -283,7 +283,8 @@ BASE_FEATURE(kShoppingList, "ShoppingList", base::FEAT
 
 BASE_FEATURE(kShoppingList, "ShoppingList", base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShoppingListRegionLaunched,
              "ShoppingListRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
