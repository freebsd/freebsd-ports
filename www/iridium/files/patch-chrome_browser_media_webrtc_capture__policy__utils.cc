--- chrome/browser/media/webrtc/capture_policy_utils.cc.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/media/webrtc/capture_policy_utils.cc
@@ -140,7 +140,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
 }
 
 bool IsGetAllScreensMediaAllowedForAnySite(content::BrowserContext* context) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
@@ -175,7 +175,7 @@ bool IsGetAllScreensMediaAllowedForAnySite(content::Br
 
 bool IsGetAllScreensMediaAllowed(content::BrowserContext* context,
                                  const GURL& url) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
