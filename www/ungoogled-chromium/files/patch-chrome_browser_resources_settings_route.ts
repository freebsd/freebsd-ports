--- chrome/browser/resources/settings/route.ts.orig	2023-02-11 09:11:04 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -215,7 +215,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
