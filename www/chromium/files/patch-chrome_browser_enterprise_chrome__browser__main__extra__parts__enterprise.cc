--- chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.cc.orig	2025-12-05 10:12:50 UTC
+++ chrome/browser/enterprise/chrome_browser_main_extra_parts_enterprise.cc
@@ -7,7 +7,7 @@
 #include "components/enterprise/buildflags/buildflags.h"
 #include "content/public/browser/browser_thread.h"
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
 #include "chrome/browser/enterprise/connectors/analysis/content_analysis_sdk_manager.h"  // nogncheck
 #include "chrome/browser/enterprise/connectors/connectors_service.h"  // nogncheck
@@ -53,7 +53,7 @@ ChromeBrowserMainExtraPartsEnterprise::ChromeBrowserMa
 ChromeBrowserMainExtraPartsEnterprise::
     ~ChromeBrowserMainExtraPartsEnterprise() = default;
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(ENTERPRISE_LOCAL_CONTENT_ANALYSIS)
 void ChromeBrowserMainExtraPartsEnterprise::PostProfileInit(
     Profile* profile,
