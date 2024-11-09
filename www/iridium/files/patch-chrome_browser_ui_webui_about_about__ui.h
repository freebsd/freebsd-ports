--- chrome/browser/ui/webui/about/about_ui.h.orig	2024-11-04 08:56:03 UTC
+++ chrome/browser/ui/webui/about/about_ui.h
@@ -50,7 +50,7 @@ class TermsUIConfig : public AboutUIConfigBase {
 };
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // chrome://linux-proxy-config
 class LinuxProxyConfigUI : public AboutUIConfigBase {
  public:
