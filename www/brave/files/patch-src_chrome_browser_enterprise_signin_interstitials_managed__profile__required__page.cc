--- src/chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc
@@ -95,7 +95,7 @@ void ManagedProfileRequiredPage::Command
 
   switch (cmd) {
     case security_interstitials::CMD_DONT_PROCEED:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (ManagedProfileRequiredNavigationThrottle::IsBlockingNavigations(
               web_contents()->GetBrowserContext())) {
         ManagedProfileRequiredNavigationThrottle::ShowBlockedWindow(
