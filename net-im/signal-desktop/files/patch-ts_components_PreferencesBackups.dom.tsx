--- ts/components/PreferencesBackups.dom.tsx.orig	2026-04-10 16:55:14 UTC
+++ ts/components/PreferencesBackups.dom.tsx
@@ -88,7 +88,7 @@ export function PreferencesBackups({
   locale: string;
   onBackupKeyViewed: ({ backupKeyHash }: { backupKeyHash: string }) => void;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   settingsLocation: SettingsLocation;
   backupMediaDownloadStatus: BackupMediaDownloadStatusType | undefined;
   cancelBackupMediaDownload: () => void;
