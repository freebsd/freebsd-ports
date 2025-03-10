--- setup.py.orig	2025-02-02 18:51:01 UTC
+++ setup.py
@@ -162,12 +162,14 @@ for subdir in icon_subdir_list:
 
 #for path in glob.glob('locale/*'):
 #    param_list.append((locale_path, [path]))
-for root, dirs, files in os.walk('locale'):
-    for file in files:
-        param_list.append((
-            os.path.join('/usr/share/locale', os.path.relpath(root, 'locale')),
-            [os.path.join(root, file)]
-        ))
+with_locale = os.environ.get('WITH_LOCALE', None)
+if with_locale is not None:
+    for root, dirs, files in os.walk('locale'):
+        for file in files:
+            param_list.append((
+                os.path.join('/usr/share/locale', os.path.relpath(root, 'locale')),
+                [os.path.join(root, file)]
+            ))
 
 for path in glob.glob('sounds/*'):
     param_list.append((sound_path, [path]))
