--- chrome/browser/resources/settings/route.js.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/resources/settings/route.js
@@ -184,7 +184,7 @@ function createBrowserSettingsRoutes() {
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="chromeos or is_linux">
+    // <if expr="chromeos or is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
