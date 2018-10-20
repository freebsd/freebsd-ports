--- setup.py.orig	2018-10-20 16:02:34 UTC
+++ setup.py
@@ -190,17 +190,17 @@ else:
 def get_version():
     """Get a valid pywikibot module version string."""
     version = '3.0'
-    try:
-        import subprocess
-        date = subprocess.check_output(
-            ['git', 'log', '-1', '--format=%ci']).strip()
-        date = date.decode().split(' ')[0].replace('-', '')
-        version += '.' + date
-        if 'sdist' not in sys.argv:
-            version += '.dev0'
-    except Exception as e:
-        print(e)
-        version += '.dev0'
+    #try:
+    #    import subprocess
+    #    date = subprocess.check_output(
+    #        ['git', 'log', '-1', '--format=%ci']).strip()
+    #    date = date.decode().split(' ')[0].replace('-', '')
+    #    version += '.' + date
+    #    if 'sdist' not in sys.argv:
+    #        version += '.dev0'
+    #except Exception as e:
+    #    print(e)
+    #    version += '.dev0'
     return version
 
 
