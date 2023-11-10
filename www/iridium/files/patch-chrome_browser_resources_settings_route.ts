--- chrome/browser/resources/settings/route.ts.orig	2023-10-21 11:51:27 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -236,7 +236,7 @@ function createBrowserSettingsRoutes(): SettingsRoutes
     r.ACCESSIBILITY = r.ADVANCED.createSection(
         '/accessibility', 'a11y', loadTimeData.getString('a11yPageTitle'));
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
