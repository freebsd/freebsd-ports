--- ts/components/LocalBackupExportWorkflow.dom.tsx.orig	2026-04-10 16:56:00 UTC
+++ ts/components/LocalBackupExportWorkflow.dom.tsx
@@ -24,7 +24,7 @@ export type PropsType = {
   clearWorkflow: () => void;
   i18n: LocalizerType;
   openFileInFolder: (path: string) => void;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   workflow: LocalBackupExportWorkflowType;
 };
 
@@ -133,7 +133,7 @@ export function LocalBackupExportWorkflow({
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
       );
-    } else if (osName === 'linux') {
+    } else if (osName === 'linux' || osName === 'freebsd') {
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
       );
