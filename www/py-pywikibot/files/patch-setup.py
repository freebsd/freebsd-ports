--- setup.py.orig	2020-04-29 18:50:22 UTC
+++ setup.py
@@ -168,22 +168,22 @@ def get_version(name):
     @rtype: str
     """
     version = '3.0'
-    try:
-        import subprocess
-        date = subprocess.check_output(
-            ['git', 'log', '-1', '--format=%ci']).strip()
-        date = date.decode().split(' ', 1)[0].replace('-', '')
-        version += '.' + date
-        if 'sdist' not in sys.argv:
-            version += '.dev0'
-    except Exception as e:
-        print(e)
-        from pkg_resources import get_distribution, DistributionNotFound
-        try:
-            version = get_distribution(name).version
-        except DistributionNotFound as e:
-            print(e)
-            version += '.dev0'
+    #try:
+    #    import subprocess
+    #    date = subprocess.check_output(
+    #        ['git', 'log', '-1', '--format=%ci']).strip()
+    #    date = date.decode().split(' ', 1)[0].replace('-', '')
+    #    version += '.' + date
+    #    if 'sdist' not in sys.argv:
+    #        version += '.dev0'
+    #except Exception as e:
+    #    print(e)
+    #    from pkg_resources import get_distribution, DistributionNotFound
+    #    try:
+    #        version = get_distribution(name).version
+    #    except DistributionNotFound as e:
+    #        print(e)
+    #        version += '.dev0'
     return version
 
 
