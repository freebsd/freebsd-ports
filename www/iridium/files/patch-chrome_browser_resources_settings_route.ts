--- chrome/browser/resources/settings/route.ts.orig	2023-04-22 17:45:15 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -223,7 +223,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
