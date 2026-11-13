--- components/browser_sync/sync_to_signin_migration.cc.orig	2026-11-11 14:44:17 UTC
+++ components/browser_sync/sync_to_signin_migration.cc
@@ -106,7 +106,7 @@ enum class SyncSetupIncompleteMigrationDecision {
 // LINT.ThenChange(/tools/metrics/histograms/metadata/sync/enums.xml:SyncSetupIncompleteMigrationDecision)
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The state of the Reading List pref migration for a signed-in, non-syncing
 // user, as determined on startup by MaybeFixUpPreviouslyMigratedUser.
 // These values are persisted to logs. Entries should not be renumbered and
@@ -321,7 +321,7 @@ void UndoSyncToSigninMigration(PrefService* pref_servi
       syncer::prefs::internal::kMigrateExtensionsFromLocalToAccount);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RecordReadingListPrefMigrationState(ReadingListPrefMigrationState state) {
   base::UmaHistogramEnumeration(
       "Sync.SyncToSigninMigration.ReadingListPrefMigrationState", state);
@@ -521,7 +521,7 @@ void MaybeMigrateSyncingUserToSignedInInternal(
       UndoSyncToSigninMigration(pref_service);
       return;
     case SyncToSigninMigrationDecision::kDontMigrateNotSyncing:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No migration needed. But the user may have been migrated in a previous
       // browser run, in which case some fix-ups may be required.
       MaybeFixUpPreviouslyMigratedUser(pref_service);
