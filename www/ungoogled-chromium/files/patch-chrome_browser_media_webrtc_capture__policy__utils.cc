--- chrome/browser/media/webrtc/capture_policy_utils.cc.orig	2023-05-05 12:12:41 UTC
+++ chrome/browser/media/webrtc/capture_policy_utils.cc
@@ -121,7 +121,7 @@ AllowedScreenCaptureLevel GetAllowedCaptureLevel(const
 
 bool IsGetDisplayMediaSetSelectAllScreensAllowedForAnySite(
     content::BrowserContext* context) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
@@ -148,7 +148,7 @@ bool IsGetDisplayMediaSetSelectAllScreensAllowedForAny
 bool IsGetDisplayMediaSetSelectAllScreensAllowed(
     content::BrowserContext* context,
     const GURL& url) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile)
     return false;
