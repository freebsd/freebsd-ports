--- chrome/browser/resources/settings/route.ts.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -240,7 +240,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
