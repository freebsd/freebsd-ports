--- chrome/browser/resources/settings/route.ts.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -179,7 +179,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
