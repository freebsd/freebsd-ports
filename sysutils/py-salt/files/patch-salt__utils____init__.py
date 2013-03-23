--- ./salt/utils/__init__.py.orig	2013-03-19 09:30:55.000000000 +0400
+++ ./salt/utils/__init__.py	2013-03-20 20:22:28.000000000 +0400
@@ -228,6 +228,15 @@
         # default path based on busybox's default
         default_path = "/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin"
 
+        p = os.environ.get('PATH')
+        if p is not None:
+            pp = p.split(os.pathsep)
+            if '/usr/local/bin' not in pp:
+                pp.append('/usr/local/bin')
+            if '/usr/local/sbin' not in pp:
+                pp.append('/usr/local/sbin')
+            os.environ['PATH'] = os.pathsep.join(pp)
+
         for path in os.environ.get('PATH', default_path).split(os.pathsep):
             full_path = os.path.join(path, exe)
             if os.access(full_path, os.X_OK):
