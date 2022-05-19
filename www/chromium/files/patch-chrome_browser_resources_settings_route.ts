--- chrome/browser/resources/settings/route.ts.orig	2022-05-19 14:06:27 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -188,7 +188,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
