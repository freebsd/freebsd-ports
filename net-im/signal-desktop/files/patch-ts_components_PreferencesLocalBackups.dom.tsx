--- ts/components/PreferencesLocalBackups.dom.tsx.orig	2026-04-10 16:52:23 UTC
+++ ts/components/PreferencesLocalBackups.dom.tsx
@@ -73,7 +73,7 @@ export function PreferencesLocalBackups({
   localBackupFolder: string | undefined;
   onBackupKeyViewed: ({ backupKeyHash }: { backupKeyHash: string }) => void;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   settingsLocation: SettingsLocation;
   pickLocalBackupFolder: () => Promise<string | undefined>;
   previouslyViewedBackupKeyHash: string | undefined;
@@ -162,7 +162,7 @@ export function PreferencesLocalBackups({
     showInFolderText = i18n(
       'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
     );
-  } else if (osName === 'linux') {
+  } else if (osName === 'linux' || osName === 'freebsd') {
     showInFolderText = i18n(
       'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
     );
