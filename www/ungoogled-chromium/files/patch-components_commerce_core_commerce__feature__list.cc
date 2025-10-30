--- components/commerce/core/commerce_feature_list.cc.orig	2025-11-01 06:40:37 UTC
+++ components/commerce/core/commerce_feature_list.cc
@@ -178,7 +178,7 @@ BASE_FEATURE(kShoppingAlternateServer, base::FEATURE_D
 const char kDiscountOnShoppyPageParam[] = "discount-on-shoppy-page";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
 const base::FeatureParam<bool> kDiscountOnShoppyPage{
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, true};
 #else
@@ -191,7 +191,7 @@ const char kMerchantWideBehaviorParam[] = "merchant-wi
 const char kNonMerchantWideBehaviorParam[] = "non-merchant-wide-behavior";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kDiscountDialogAutoPopupBehaviorSetting,
              base::FEATURE_ENABLED_BY_DEFAULT);
 const base::FeatureParam<int> kHistoryClustersBehavior{
