--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js
@@ -24,7 +24,7 @@ cr.define('settings', function() {
 
     useDefaultTheme() {}
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     useSystemTheme() {}
 
     // </if>
@@ -64,7 +64,7 @@ cr.define('settings', function() {
       chrome.send('useDefaultTheme');
     }
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     /** @override */
     useSystemTheme() {
       chrome.send('useSystemTheme');
