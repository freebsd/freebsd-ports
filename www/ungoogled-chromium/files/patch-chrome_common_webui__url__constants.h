--- chrome/common/webui_url_constants.h.orig	2025-02-20 09:59:21 UTC
+++ chrome/common/webui_url_constants.h
@@ -497,18 +497,18 @@ inline constexpr char kChromeUIOsUrlAppURL[] = "chrome
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIConnectorsInternalsHost[] =
     "connectors-internals";
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDiscardsHost[] = "discards";
 inline constexpr char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIWebAppSettingsHost[] = "app-settings";
 inline constexpr char kChromeUIWebAppSettingsURL[] = "chrome://app-settings/";
 inline constexpr char kChromeUIWhatsNewHost[] = "whats-new";
@@ -520,11 +520,11 @@ inline constexpr char kChromeUILinuxProxyConfigHost[] 
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUISandboxHost[] = "sandbox";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIBrowserSwitchHost[] = "browser-switch";
 inline constexpr char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 inline constexpr char kChromeUIIntroDefaultBrowserSubPage[] = "default-browser";
@@ -545,7 +545,7 @@ inline constexpr char kChromeUIProfilePickerStartupQue
 inline constexpr char kChromeUIProfilePickerUrl[] = "chrome://profile-picker/";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 inline constexpr char kChromeUITabModalConfirmDialogHost[] =
