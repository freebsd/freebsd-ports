--- components/search_engines/template_url_service.cc.orig	2025-01-15 09:18:26 UTC
+++ components/search_engines/template_url_service.cc
@@ -3062,7 +3062,7 @@ bool TemplateURLService::MatchesDefaultSearchProvider(
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs,
       base::BindRepeating(&TemplateURLService::EnterpriseSiteSearchChanged,
