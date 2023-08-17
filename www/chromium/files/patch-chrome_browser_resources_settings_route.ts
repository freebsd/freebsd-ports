--- chrome/browser/resources/settings/route.ts.orig	2023-08-17 07:33:31 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -241,7 +241,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
