--- chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/webui/user_education_internals/user_education_internals_page_handler_impl.cc
@@ -47,7 +47,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/resource_path.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_navigator_params.h"
 #include "net/base/url_util.h"
@@ -87,7 +87,7 @@ user_education::NewBadgeRegistry* GetNewBadgeRegistry(
 }
 
 whats_new::WhatsNewRegistry* GetWhatsNewRegistry() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process->GetFeatures()->whats_new_registry();
 #else
   return nullptr;
@@ -877,7 +877,7 @@ void UserEducationInternalsPageHandlerImpl::ClearWhats
 }
 
 void UserEducationInternalsPageHandlerImpl::LaunchWhatsNewStaging() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   GURL url = net::AppendQueryParameter(GURL(chrome::kChromeUIWhatsNewURL),
                                        "staging", "true");
   NavigateParams params(profile_, url, ui::PAGE_TRANSITION_TYPED);
