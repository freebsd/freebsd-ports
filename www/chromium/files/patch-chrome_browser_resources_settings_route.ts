--- chrome/browser/resources/settings/route.ts.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/resources/settings/route.ts
@@ -187,7 +187,7 @@ function createBrowserSettingsRoutes(): Partial<Settin
 
     r.ACCESSIBILITY = r.ADVANCED.createSection('/accessibility', 'a11y');
 
-    // <if expr="is_linux">
+    // <if expr="is_posix">
     r.CAPTIONS = r.ACCESSIBILITY.createChild('/captions');
     // </if>
 
