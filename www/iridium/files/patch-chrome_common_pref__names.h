--- chrome/common/pref_names.h.orig	2024-08-01 05:47:53 UTC
+++ chrome/common/pref_names.h
@@ -1340,7 +1340,7 @@ inline constexpr char kUseAshProxy[] = "lacros.proxy.u
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Linux specific preference on whether we should match the system theme.
 inline constexpr char kSystemTheme[] = "extensions.theme.system_theme";
 #endif
@@ -1483,7 +1483,7 @@ inline constexpr char kShowUpdatePromotionInfoBar[] =
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 inline constexpr char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -2088,7 +2088,7 @@ inline constexpr char kDownloadDefaultDirectory[] =
 inline constexpr char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 inline constexpr char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -2528,14 +2528,14 @@ inline constexpr char kMediaStorageIdSalt[] = "media.s
 inline constexpr char kMediaCdmOriginData[] = "media.cdm.origin_data";
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A boolean pref to determine whether or not the network service is running
 // sandboxed.
 inline constexpr char kNetworkServiceSandboxEnabled[] =
     "net.network_service_sandbox";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Records whether the user has seen an HTTP auth "negotiate" header.
 inline constexpr char kReceivedHttpAuthNegotiateHeader[] =
     "net.received_http_auth_negotiate_headers";
@@ -2613,7 +2613,7 @@ inline constexpr char kAmbientAuthenticationInPrivateM
 inline constexpr char kBasicAuthOverHttpEnabled[] =
     "auth.basic_over_http_enabled";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateAllowlist.
 inline constexpr char kAuthNegotiateDelegateByKdcPolicy[] =
@@ -3133,7 +3133,7 @@ inline constexpr char kDeviceWeeklyScheduledSuspend[] 
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Defines administrator-set availability of Chrome for Testing.
 inline constexpr char kChromeForTestingAllowed[] = "chrome_for_testing.allowed";
 #endif
@@ -3706,7 +3706,7 @@ inline constexpr char kFileOrDirectoryPickerWithoutGes
 inline constexpr char kSandboxExternalProtocolBlocked[] =
     "profile.sandbox_external_protocol_blocked";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that indicates if system notifications are allowed to be used in
 // place of Chrome notifications.
 inline constexpr char kAllowSystemNotifications[] =
@@ -3755,7 +3755,7 @@ inline constexpr char kCACertificateManagementAllowed[
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnforceLocalAnchorConstraintsEnabled[] =
     "enforce_local_anchor_constraints_enabled";
 #endif
@@ -4063,7 +4063,7 @@ inline constexpr char kPrintingOAuth2AuthorizationServ
     "printing.oauth2_authorization_servers";
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this exists and is true, Chrome may run system DNS resolution out of the
 // network process. If false, Chrome will run system DNS resolution in the
 // network process. If non-existent, Chrome will decide where to run system DNS
