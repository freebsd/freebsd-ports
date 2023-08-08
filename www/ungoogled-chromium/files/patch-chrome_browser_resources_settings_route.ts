--- chrome/browser/resources/settings/route.ts.orig	2023-06-05 19:39:05 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -232,7 +232,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
