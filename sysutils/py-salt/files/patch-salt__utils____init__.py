--- ./salt/utils/__init__.py.orig	2013-10-17 21:27:29.000000000 +0400
+++ ./salt/utils/__init__.py	2013-10-25 10:52:19.000000000 +0400
@@ -266,6 +266,15 @@
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
