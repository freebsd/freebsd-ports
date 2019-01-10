--- chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js.orig	2019-01-09 12:44:51.519192000 +0100
+++ chrome/browser/resources/settings/appearance_page/appearance_browser_proxy.js	2019-01-09 12:45:25.405099000 +0100
@@ -35,7 +35,7 @@
 
     useDefaultTheme() {}
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     useSystemTheme() {}
 
     // </if>
@@ -93,7 +93,7 @@
       chrome.send('useDefaultTheme');
     }
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     /** @override */
     useSystemTheme() {
       chrome.send('useSystemTheme');
