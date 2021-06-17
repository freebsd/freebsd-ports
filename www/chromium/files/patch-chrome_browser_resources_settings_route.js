--- chrome/browser/resources/settings/route.js.orig	2021-06-11 09:29:55 UTC
+++ chrome/browser/resources/settings/route.js
@@ -183,7 +183,7 @@ function createBrowserSettingsRoutes() {
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="chromeos or is_linux">
+    // <if expr="chromeos or is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
