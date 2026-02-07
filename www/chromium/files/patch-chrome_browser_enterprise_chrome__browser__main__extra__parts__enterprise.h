--- chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.h
@@ -25,7 +25,7 @@ class ChromeBrowserMainExtraPartsEnterprise
   ~ChromeBrowserMainExtraPartsEnterprise() override;
 
   // ChromeBrowserMainExtraParts:
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
   void PostProfileInit(Profile* profile, bool is_initial_profile) override;
 #endif
