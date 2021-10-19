--- chrome/common/pref_names.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/common/pref_names.cc
@@ -1131,7 +1131,7 @@ const char kAllowedDomainsForApps[] = "settings.allowe
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1234,7 +1234,7 @@ const char kShowUpdatePromotionInfoBar[] =
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1700,7 +1700,7 @@ const char kDownloadDefaultDirectory[] = "download.def
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
@@ -1979,7 +1979,7 @@ const char kWebAppsPreferences[] = "web_apps.web_app_i
 const char kWebAppsIsolationState[] = "web_apps.isolation_state";
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // Dictionary that maps origins to web apps that can act as URL handlers.
 const char kWebAppsUrlHandlerInfo[] = "web_apps.url_handler_info";
 #endif
@@ -2101,12 +2101,12 @@ const char kAmbientAuthenticationInPrivateModesEnabled
 // requests.
 const char kBasicAuthOverHttpEnabled[] = "auth.basic_over_http_enabled";
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateAllowlist.
 const char kAuthNegotiateDelegateByKdcPolicy[] =
     "auth.negotiate_delegate_by_kdc_policy";
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX) || defined(OS_FUCHSIA)
 // Boolean that specifies whether NTLMv2 is enabled.
@@ -3059,7 +3059,7 @@ const char kAutoplayWhitelist[] = "media.autoplay_whit
 const char kBlockAutoplayEnabled[] = "media.block_autoplay";
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Boolean that indicates if native notifications are allowed to be used in
 // place of Chrome notifications. Will be replaced by kAllowSystemNotifications.
 const char kAllowNativeNotifications[] = "native_notifications.allowed";
@@ -3067,7 +3067,7 @@ const char kAllowNativeNotifications[] = "native_notif
 // Boolean that indicates if system notifications are allowed to be used in
 // place of Chrome notifications.
 const char kAllowSystemNotifications[] = "system_notifications.allowed";
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // Integer that holds the value of the next persistent notification ID to be
 // used.
