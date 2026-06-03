--- ts/components/PlaintextExportWorkflow.dom.tsx.orig	2026-04-10 16:56:57 UTC
+++ ts/components/PlaintextExportWorkflow.dom.tsx
@@ -24,7 +24,7 @@ export type PropsType = {
   clearWorkflow: () => unknown;
   i18n: LocalizerType;
   openFileInFolder: (path: string) => unknown;
-  osName: 'linux' | 'macos' | 'windows' | undefined;
+  osName: 'linux' | 'macos' | 'windows' | 'freebsd' | undefined;
   verifyWithOSForExport: (includeMedia: boolean) => unknown;
   workflow: PlaintextExportWorkflowType;
 };
@@ -221,7 +221,7 @@ export function PlaintextExportWorkflow({
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Mac'
       );
-    } else if (osName === 'linux') {
+    } else if (osName === 'linux' || osName === 'freebsd') {
       showInFolderText = i18n(
         'icu:PlaintextExport--CompleteDialog--ShowFiles--Linux'
       );
