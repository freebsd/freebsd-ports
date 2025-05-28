--- ts/components/fun/isFunPickerEnabled.tsx.orig	2025-05-26 15:01:58 UTC
+++ ts/components/fun/isFunPickerEnabled.tsx
@@ -3,5 +3,5 @@ export function isFunPickerEnabled(): boolean {
 import * as RemoteConfig from '../../RemoteConfig';
 
 export function isFunPickerEnabled(): boolean {
-  return RemoteConfig.isEnabled('desktop.funPicker');
+  return RemoteConfig.isEnabled('desktop.funPicker.prod');
 }
