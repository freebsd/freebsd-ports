--- chrome/browser/profiles/profiles_state.cc.orig	2024-07-31 14:19:23 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -195,7 +195,7 @@ bool IsGuestModeRequested(const base::CommandLine& com
                           PrefService* local_state,
                           bool show_warning) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DCHECK(local_state);
 
   // Check if guest mode enforcement commandline switch or policy are provided.
@@ -242,7 +242,7 @@ bool IsGuestModeEnabled() {
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // If there are any supervised profiles, disable guest mode.
   if (base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers) &&
@@ -258,7 +258,7 @@ bool IsGuestModeEnabled() {
 }
 
 bool IsGuestModeEnabled(const Profile& profile) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers)) {
     ProfileAttributesEntry* profile_attributes =
