--- components/search_engines/template_url_service.cc.orig	2024-02-03 15:42:55 UTC
+++ components/search_engines/template_url_service.cc
@@ -2588,7 +2588,7 @@ bool TemplateURLService::MatchesDefaultSearchProvider(
 std::unique_ptr<EnterpriseSiteSearchManager>
 TemplateURLService::GetEnterpriseSiteSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(omnibox::kSiteSearchSettingsPolicy)
              ? std::make_unique<EnterpriseSiteSearchManager>(
                    prefs, base::BindRepeating(
