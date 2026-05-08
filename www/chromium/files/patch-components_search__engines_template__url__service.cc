--- components/search_engines/template_url_service.cc.orig	2026-05-07 17:02:56 UTC
+++ components/search_engines/template_url_service.cc
@@ -3667,7 +3667,7 @@ bool TemplateURLService::MatchesDefaultSearchProvider(
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs, base::BindRepeating(&TemplateURLService::EnterpriseSearchChanged,
                                  base::Unretained(this)));
