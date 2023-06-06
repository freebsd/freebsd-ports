--- chrome/browser/media/webrtc/capture_policy_utils.cc.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/media/webrtc/capture_policy_utils.cc
@@ -125,7 +125,7 @@ AllowedScreenCaptureLevel GetAllowedCaptureLevel(const
 
 bool IsGetDisplayMediaSetSelectAllScreensAllowedForAnySite(
     content::BrowserContext* context) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
@@ -162,7 +162,7 @@ bool IsGetDisplayMediaSetSelectAllScreensAllowedForAny
 bool IsGetDisplayMediaSetSelectAllScreensAllowed(
     content::BrowserContext* context,
     const GURL& url) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
