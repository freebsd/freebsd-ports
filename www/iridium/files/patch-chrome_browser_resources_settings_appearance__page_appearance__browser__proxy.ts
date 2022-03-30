--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts.orig	2022-03-28 18:11:04 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.ts
@@ -16,7 +16,7 @@ export interface AppearanceBrowserProxy {
 
   useDefaultTheme(): void;
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_bsd and not chromeos">
   useSystemTheme(): void;
   // </if>
 
@@ -44,7 +44,7 @@ export class AppearanceBrowserProxyImpl implements App
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_bsd and not chromeos">
   useSystemTheme() {
     chrome.send('useSystemTheme');
   }
