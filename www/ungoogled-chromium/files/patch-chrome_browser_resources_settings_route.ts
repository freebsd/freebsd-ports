--- chrome/browser/resources/settings/route.ts.orig	2023-09-17 07:59:53 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -231,7 +231,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
