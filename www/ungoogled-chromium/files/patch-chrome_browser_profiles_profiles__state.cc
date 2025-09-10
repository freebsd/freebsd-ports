--- chrome/browser/profiles/profiles_state.cc.orig	2025-09-10 13:22:16 UTC
+++ chrome/browser/profiles/profiles_state.cc
@@ -190,7 +190,7 @@ bool IsGuestModeRequested(const base::CommandLine& com
                           PrefService* local_state,
                           bool show_warning) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DCHECK(local_state);
 
   // Check if guest mode enforcement commandline switch or policy are provided.
@@ -226,7 +226,7 @@ bool IsGuestModeEnabled() {
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // If there are any supervised profiles, disable guest mode.
   if (std::ranges::any_of(g_browser_process->profile_manager()
                               ->GetProfileAttributesStorage()
@@ -242,7 +242,7 @@ bool IsGuestModeEnabled() {
 }
 
 bool IsGuestModeEnabled(const Profile& profile) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ProfileAttributesEntry* profile_attributes =
       g_browser_process->profile_manager()
           ->GetProfileAttributesStorage()
