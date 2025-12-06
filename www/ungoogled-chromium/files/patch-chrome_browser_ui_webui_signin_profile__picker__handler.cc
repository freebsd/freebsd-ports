--- chrome/browser/ui/webui/signin/profile_picker_handler.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/webui/signin/profile_picker_handler.cc
@@ -173,7 +173,7 @@ base::Value::Dict CreateProfileState(const ProfileAttr
       IDS_PROFILE_PICKER_PROFILE_CARD_LABEL, local_profile_name);
   if (entry->GetIsManaged() == signin::Tribool::kTrue) {
     profile_entry.Set("avatarBadge", "cr:domain");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (entry->IsSupervised()) {
     profileCardButtonLabel = l10n_util::GetStringFUTF16(
         IDS_PROFILE_PICKER_PROFILE_CARD_LABEL_SUPERVISED, local_profile_name);
