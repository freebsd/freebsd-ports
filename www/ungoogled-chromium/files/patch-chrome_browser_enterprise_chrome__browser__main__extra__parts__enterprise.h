--- chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h
@@ -29,7 +29,7 @@ class ChromeBrowserMainExtraPartsEnterprise
   ~ChromeBrowserMainExtraPartsEnterprise() override;
 
   // ChromeBrowserMainExtraParts:
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
   void PostProfileInit(Profile* profile, bool is_initial_profile) override;
 #endif
