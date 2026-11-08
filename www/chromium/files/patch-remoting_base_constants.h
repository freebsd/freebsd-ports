--- remoting/base/constants.h.orig	2026-10-18 13:29:39 UTC
+++ remoting/base/constants.h
@@ -30,7 +30,7 @@ const int kDefaultDpi = 96;
 // The video frame rate.
 constexpr int kTargetFrameRate = 30;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeRemoteDesktopSessionEnvVar[] =
     "CHROME_REMOTE_DESKTOP_SESSION";
 
