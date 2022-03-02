--- chrome/common/webui_url_constants.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/common/webui_url_constants.h
@@ -371,18 +371,18 @@ extern const char kOsUIFlagsURL[];
 extern const char kOsUIVersionURL[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIWebUIJsErrorHost[];
 extern const char kChromeUIWebUIJsErrorURL[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIConnectorsInternalsHost[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIDiscardsHost[];
 extern const char kChromeUIDiscardsURL[];
 #endif
@@ -397,14 +397,14 @@ extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kChromeUISandboxHost[];
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 extern const char kChromeUIBrowserSwitchHost[];
 extern const char kChromeUIBrowserSwitchURL[];
 extern const char kChromeUIEnterpriseProfileWelcomeHost[];
@@ -416,7 +416,7 @@ extern const char kChromeUIProfilePickerUrl[];
 extern const char kChromeUIProfilePickerStartupQuery[];
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
