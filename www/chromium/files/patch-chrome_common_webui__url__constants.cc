--- chrome/common/webui_url_constants.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/common/webui_url_constants.cc
@@ -424,18 +424,18 @@ const char kOsUIFlagsURL[] = "os://flags";
 const char kOsUIVersionURL[] = "os://version";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kChromeUIWebUIJsErrorHost[] = "webuijserror";
 const char kChromeUIWebUIJsErrorURL[] = "chrome://webuijserror/";
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kChromeUIConnectorsInternalsHost[] = "connectors-internals";
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kChromeUIDiscardsHost[] = "discards";
 const char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
@@ -450,14 +450,14 @@ const char kChromeUILinuxProxyConfigHost[] = "linux-pr
 #endif
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
 const char kChromeUISandboxHost[] = "sandbox";
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_FUCHSIA) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 const char kChromeUIBrowserSwitchHost[] = "browser-switch";
 const char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 const char kChromeUIEnterpriseProfileWelcomeHost[] =
@@ -472,7 +472,7 @@ const char kChromeUIProfilePickerUrl[] = "chrome://pro
 const char kChromeUIProfilePickerStartupQuery[] = "startup";
 #endif
 
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(TOOLKIT_VIEWS)) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(TOOLKIT_VIEWS)) || \
     defined(USE_AURA)
 const char kChromeUITabModalConfirmDialogHost[] = "tab-modal-confirm-dialog";
 #endif
@@ -661,18 +661,18 @@ const char* const kChromeHostURLs[] = {
     kChromeUIAssistantOptInHost,
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     kChromeUIConnectorsInternalsHost,
 #endif
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     kChromeUIDiscardsHost,
 #endif
 #if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_ANDROID)
     kChromeUILinuxProxyConfigHost,
 #endif
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     kChromeUISandboxHost,
 #endif
 #if defined(OS_WIN)
@@ -729,7 +729,7 @@ const char* const kChromeDebugURLs[] = {
     blink::kChromeUIGpuJavaCrashURL,
     kChromeUIJavaCrashURL,
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     kChromeUIWebUIJsErrorURL,
 #endif
     kChromeUIQuitURL,
