--- components/sync/service/sync_prefs.cc.orig	2026-10-18 13:29:39 UTC
+++ components/sync/service/sync_prefs.cc
@@ -192,7 +192,7 @@ void SyncPrefs::RegisterProfilePrefs(PrefRegistrySimpl
       prefs::internal::kMigrateExtensionsFromLocalToAccount, false);
   registry->RegisterBooleanPref(
       prefs::internal::kMigrateThemeFromLocalToAccount, false);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       prefs::internal::kReadingListPrefMigratedToAccount, false);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -869,7 +869,7 @@ bool SyncPrefs::MaybeMigratePrefsForSyncToSigninPart1(
           update_selected_types_dict->EnsureDict(
               signin::GaiaIdHash::FromGaiaId(gaia_id).ToBase64());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Preserve the user's existing enabled state for Bookmarks, Reading List,
       // and Preferences. Otherwise, use the default value, which will be true
       // after `kReplaceSyncPromosWithSignInPromos`.
@@ -1062,7 +1062,7 @@ void SyncPrefs::MigrateGlobalDataTypePrefsToAccount(Pr
                         saved_tab_groups_enabled);
   account_settings->Set(GetPrefNameForType(UserSelectableType::kExtensions),
                         extensions_enabled);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Record that this migration now covers the Reading List toggle, to be able
   // to identify users who were migrated before it did (crbug.com/568406887).
   pref_service->SetBoolean(prefs::internal::kReadingListPrefMigratedToAccount,
