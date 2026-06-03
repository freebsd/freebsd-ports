--- ts/components/Preferences.dom.tsx.orig	2026-04-10 16:54:08 UTC
+++ ts/components/Preferences.dom.tsx
@@ -162,7 +162,7 @@ export type PropsDataType = {
   settingsLocation: SettingsLocation;
   lastSyncTime?: number;
   notificationContent: NotificationSettingType;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   phoneNumber: string | undefined;
   selectedCamera?: string;
   selectedMicrophone?: AudioDevice;
