--- ts/state/ducks/user.preload.ts.orig	2023-10-19 19:29:53 UTC
+++ ts/state/ducks/user.preload.ts
@@ -23,7 +23,7 @@ export type UserStateType = Readonly<{
   isMainWindowMaximized: boolean;
   localeMessages: LocaleMessagesType;
   menuOptions: MenuOptionsType;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   ourAci: AciString | undefined;
   ourConversationId: string | undefined;
   ourDeviceId: number | undefined;
@@ -114,7 +114,7 @@ export function getEmptyState(): UserStateType {
 // Reducer
 
 export function getEmptyState(): UserStateType {
-  let osName: 'windows' | 'macos' | 'linux' | undefined;
+  let osName: 'windows' | 'macos' | 'linux' | 'freebsd' | undefined;
 
   if (OS.isWindows()) {
     osName = 'windows';
@@ -122,6 +122,8 @@ export function getEmptyState(): UserStateType {
     osName = 'macos';
   } else if (OS.isLinux()) {
     osName = 'linux';
+  } else if (OS.isFreeBSD()) {
+    osName = 'freebsd';
   }
 
   return {
