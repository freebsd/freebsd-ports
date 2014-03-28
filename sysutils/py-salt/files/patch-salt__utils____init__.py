--- ./salt/utils/__init__.py.orig	2014-02-19 22:21:15.000000000 +0200
+++ ./salt/utils/__init__.py	2014-03-06 10:50:07.000000000 +0200
@@ -316,6 +316,15 @@
         if os.access(exe, os.X_OK):
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
