--- ts/components/Preferences.dom.tsx.orig	2026-04-10 16:54:08 UTC
+++ ts/components/Preferences.dom.tsx
@@ -186,7 +186,7 @@ export type PropsDataType = {
   lastSyncTime?: number;
   notificationContent: NotificationSettingType;
   notifyWhileMuted: NotifyWhileMuted;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   phoneNumber: string | undefined;
   selectedCamera?: string;
   selectedMicrophone?: AudioDevice;
