--- chrome/browser/ui/browser_commands.h.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/browser_commands.h
@@ -250,7 +250,7 @@ void ProcessInterceptedChromeURLNavigationInIncognito(
 // Follows a web feed associated with the main frame of specified web contents.
 void FollowSite(Browser* browser, content::WebContents* web_contents);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Triggers the Screen AI to be run once on the |browser|.
 void RunScreenAi(Browser* browser);
 #endif  // BUILDFLAG(IS_LINUX)
