--- chrome/browser/resources/settings/route.ts.orig	2022-04-01 07:48:30 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -185,7 +185,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
