--- components/search_engines/template_url_service.cc.orig	2025-01-25 09:34:31 UTC
+++ components/search_engines/template_url_service.cc
@@ -3077,7 +3077,7 @@ bool TemplateURLService::MatchesDefaultSearchProvider(
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs,
       base::BindRepeating(&TemplateURLService::EnterpriseSiteSearchChanged,
