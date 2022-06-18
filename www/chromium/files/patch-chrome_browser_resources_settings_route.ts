--- chrome/browser/resources/settings/route.ts.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -190,7 +190,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
