--- chrome/common/pref_names.cc.orig	2019-07-24 18:58:14 UTC
+++ chrome/common/pref_names.cc
@@ -982,7 +982,7 @@ const char kForceYouTubeRestrict[] = "settings.force_y
 // only using an account that belongs to one of the domains from this pref.
 const char kAllowedDomainsForApps[] = "settings.allowed_domains_for_apps";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1076,7 +1076,7 @@ const char kShowUpdatePromotionInfoBar[] =
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1468,7 +1468,7 @@ const char kDownloadDefaultDirectory[] = "download.def
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -1730,12 +1730,12 @@ const char kAuthAndroidNegotiateAccountType[] =
 // domain sub-content requests.
 const char kAllowCrossOriginAuthPrompt[] = "auth.allow_cross_origin_prompt";
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateWhitelist.
 const char kAuthNegotiateDelegateByKdcPolicy[] =
     "auth.negotiate_delegate_by_kdc_policy";
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
 // Boolean that specifies whether NTLMv2 is enabled.
