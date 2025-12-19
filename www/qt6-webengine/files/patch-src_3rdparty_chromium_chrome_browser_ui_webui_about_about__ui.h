--- src/3rdparty/chromium/chrome/browser/ui/webui/about/about_ui.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/browser/ui/webui/about/about_ui.h
@@ -55,7 +55,7 @@ class TermsUIConfig : public AboutUIConfigBase {
 };
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // chrome://linux-proxy-config
 class LinuxProxyConfigUI : public AboutUIConfigBase {
  public:
