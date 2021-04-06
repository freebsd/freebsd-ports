--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js
@@ -23,7 +23,7 @@ export class AppearanceBrowserProxy {
 
   useDefaultTheme() {}
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_posix and not chromeos">
   useSystemTheme() {}
 
   // </if>
@@ -63,7 +63,7 @@ export class AppearanceBrowserProxyImpl {
     chrome.send('useDefaultTheme');
   }
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_posix and not chromeos">
   /** @override */
   useSystemTheme() {
     chrome.send('useSystemTheme');
