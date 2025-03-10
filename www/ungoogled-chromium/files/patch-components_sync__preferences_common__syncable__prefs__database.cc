--- components/sync_preferences/common_syncable_prefs_database.cc.orig	2025-03-09 21:38:10 UTC
+++ components/sync_preferences/common_syncable_prefs_database.cc
@@ -314,7 +314,7 @@ constexpr auto kCommonSyncablePrefsAllowlist =
           PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
