--- chrome/browser/resources/settings/route.ts.orig	2022-03-28 18:11:04 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -179,7 +179,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
