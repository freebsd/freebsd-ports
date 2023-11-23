--- src/3rdparty/chromium/chrome/browser/media/webrtc/capture_policy_utils.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/capture_policy_utils.cc
@@ -118,7 +118,7 @@ AllowedScreenCaptureLevel GetAllowedCaptureLevel(const
 
 bool IsGetDisplayMediaSetSelectAllScreensAllowedForAnySite(
     content::BrowserContext* context) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
@@ -145,7 +145,7 @@ bool IsGetDisplayMediaSetSelectAllScreensAllowedForAny
 bool IsGetDisplayMediaSetSelectAllScreensAllowed(
     content::BrowserContext* context,
     const GURL& url) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile)
     return false;
