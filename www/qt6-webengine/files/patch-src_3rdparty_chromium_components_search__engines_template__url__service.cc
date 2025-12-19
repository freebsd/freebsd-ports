--- src/3rdparty/chromium/components/search_engines/template_url_service.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/search_engines/template_url_service.cc
@@ -3229,7 +3229,7 @@ TemplateURLService::GetEnterpriseSearchManager(PrefSer
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs, base::BindRepeating(&TemplateURLService::EnterpriseSearchChanged,
                                  base::Unretained(this)));
