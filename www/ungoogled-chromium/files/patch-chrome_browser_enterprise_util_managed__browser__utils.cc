--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -319,7 +319,7 @@ void SetUserAcceptedAccountManagement(Profile* profile
   // The updated consent screen also ask the user for consent to share device
   // signals.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   profile->GetPrefs()->SetBoolean(
       device_signals::prefs::kDeviceSignalsPermanentConsentReceived, accepted);
 #endif
@@ -328,7 +328,7 @@ void SetUserAcceptedAccountManagement(Profile* profile
       profile_manager->GetProfileAttributesStorage()
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     SetEnterpriseProfileLabel(profile);
 #endif
     entry->SetUserAcceptedAccountManagement(accepted);
@@ -414,7 +414,7 @@ bool CanShowEnterpriseProfileUI(Profile* profile) {
 }
 
 bool CanShowEnterpriseBadgingForNTPFooter(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserManagementNoticeState management_notice_state =
       GetManagementNoticeStateForNTPFooter(profile);
   switch (management_notice_state) {
@@ -432,7 +432,7 @@ bool CanShowEnterpriseBadgingForNTPFooter(Profile* pro
 
 BrowserManagementNoticeState GetManagementNoticeStateForNTPFooter(
     Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* management_service =
       policy::ManagementServiceFactory::GetForProfile(profile);
   if (!management_service->IsBrowserManaged() ||
