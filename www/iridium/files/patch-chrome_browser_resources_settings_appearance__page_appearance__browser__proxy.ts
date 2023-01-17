--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts.orig	2023-01-17 19:19:00 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts
@@ -16,7 +16,7 @@ export interface AppearanceBrowserProxy {
 
   useDefaultTheme(): void;
 
-  // <if expr="is_linux">
+  // <if expr="is_posix">
   useGtkTheme(): void;
   useQtTheme(): void;
   // </if>
@@ -41,7 +41,7 @@ export class AppearanceBrowserProxyImpl implements App
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux">
+  // <if expr="is_posix">
   useGtkTheme() {
     chrome.send('useGtkTheme');
   }
