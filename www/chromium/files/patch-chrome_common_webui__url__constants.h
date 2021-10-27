--- chrome/common/webui_url_constants.h.orig	2021-09-24 04:26:00 UTC
+++ chrome/common/webui_url_constants.h
@@ -316,12 +316,12 @@ extern const char kChromeUIOSSettingsHost[];
 extern const char kChromeUIOSSettingsURL[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kChromeUIWebUIJsErrorHost[];
 extern const char kChromeUIWebUIJsErrorURL[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 extern const char kChromeUIDiscardsHost[];
 extern const char kChromeUIDiscardsURL[];
@@ -336,7 +336,7 @@ extern const char kChromeUINearbyShareURL[];
 extern const char kChromeUILinuxProxyConfigHost[];
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
 extern const char kChromeUISandboxHost[];
 #endif
@@ -344,7 +344,7 @@ extern const char kChromeUISandboxHost[];
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 extern const char kChromeUIBrowserSwitchHost[];
 extern const char kChromeUIBrowserSwitchURL[];
 extern const char kChromeUIEnterpriseProfileWelcomeHost[];
@@ -356,7 +356,7 @@ extern const char kChromeUIProfilePickerUrl[];
 extern const char kChromeUIProfilePickerStartupQuery[];
 #endif
 
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || defined(OS_BSD) || \
     defined(USE_AURA)
 extern const char kChromeUITabModalConfirmDialogHost[];
 #endif
