--- chrome/common/pref_names.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/common/pref_names.cc
@@ -1220,7 +1220,7 @@ const char kUseAshProxy[] = "lacros.proxy.use_ash_prox
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1315,7 +1315,7 @@ const char kShowUpdatePromotionInfoBar[] =
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1810,7 +1810,7 @@ const char kDownloadDirUpgraded[] = "download.director
 const char kDownloadLastCompleteTime[] = "download.last_complete_time";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -2111,7 +2111,7 @@ const char kWebAppsPreferences[] = "web_apps.web_app_i
 // its isolation requirements.
 const char kWebAppsIsolationState[] = "web_apps.isolation_state";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 // Dictionary that maps origins to web apps that can act as URL handlers.
 const char kWebAppsUrlHandlerInfo[] = "web_apps.url_handler_info";
@@ -2241,7 +2241,7 @@ const char kAmbientAuthenticationInPrivateModesEnabled
 // requests.
 const char kBasicAuthOverHttpEnabled[] = "auth.basic_over_http_enabled";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateAllowlist.
 const char kAuthNegotiateDelegateByKdcPolicy[] =
@@ -3246,7 +3246,7 @@ const char kBlockAutoplayEnabled[] = "media.block_auto
 const char kSandboxExternalProtocolBlocked[] =
     "profile.sandbox_external_protocol_blocked";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that indicates if system notifications are allowed to be used in
 // place of Chrome notifications.
 const char kAllowSystemNotifications[] = "system_notifications.allowed";
