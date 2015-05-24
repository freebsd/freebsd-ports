--- salt/utils/__init__.py.orig	2015-04-17 18:44:50 UTC
+++ salt/utils/__init__.py
@@ -372,6 +372,15 @@ def which(exe=None):
             # executable in cwd or fullpath
             return exe
 
+        p = os.environ.get('PATH')
+        if p is not None:
+            pp = p.split(os.pathsep)
+            if '/usr/local/bin' not in pp:
+                pp.append('/usr/local/bin')
+            if '/usr/local/sbin' not in pp:
+                pp.append('/usr/local/sbin')
+            os.environ['PATH'] = os.pathsep.join(pp)
+
         # default path based on busybox's default
         default_path = '/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin'
         search_path = os.environ.get('PATH', default_path)
