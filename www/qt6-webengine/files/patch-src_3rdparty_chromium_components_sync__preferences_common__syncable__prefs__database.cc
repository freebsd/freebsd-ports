--- src/3rdparty/chromium/components/sync_preferences/common_syncable_prefs_database.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/sync_preferences/common_syncable_prefs_database.cc
@@ -327,7 +327,7 @@ constexpr auto kCommonSyncablePrefsAllowlist =
           PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
