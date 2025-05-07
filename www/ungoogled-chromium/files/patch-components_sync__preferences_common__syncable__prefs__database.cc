--- components/sync_preferences/common_syncable_prefs_database.cc.orig	2025-05-06 12:23:00 UTC
+++ components/sync_preferences/common_syncable_prefs_database.cc
@@ -321,7 +321,7 @@ constexpr auto kCommonSyncablePrefsAllowlist =
           PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
