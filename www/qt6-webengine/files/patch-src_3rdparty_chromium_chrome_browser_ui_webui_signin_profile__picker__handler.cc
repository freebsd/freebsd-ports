--- src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-08-18 00:53:11 UTC
+++ src/3rdparty/chromium/chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -209,7 +209,7 @@ base::Value::Dict CreateProfileEntry(const ProfileAttr
 
   if (AccountInfo::IsManaged(entry->GetHostedDomain())) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (base::FeatureList::IsEnabled(
                  supervised_user::kShowKiteForSupervisedUsers) &&
              entry->IsSupervised()) {
@@ -1222,7 +1222,7 @@ void ProfilePickerHandler::MaybeUpdateGuestMode() {
 }
 
 void ProfilePickerHandler::MaybeUpdateGuestMode() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers)) {
     return;
