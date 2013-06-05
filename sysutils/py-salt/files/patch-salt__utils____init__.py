--- salt/utils/__init__.py.orig	2013-05-29 00:20:55.000000000 -0600
+++ salt/utils/__init__.py	    2013-05-31 10:13:41.486795573 -0600
@@ -242,6 +242,15 @@
         default_path = '/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin'
         search_path = os.environ.get('PATH', default_path)
 
+        p = os.environ.get('PATH')
+        if p is not None:
+            pp = p.split(os.pathsep)
+            if '/usr/local/bin' not in pp:
+                pp.append('/usr/local/bin')
+            if '/usr/local/sbin' not in pp:
+                pp.append('/usr/local/sbin')
+            os.environ['PATH'] = os.pathsep.join(pp)
+
         for path in search_path.split(os.pathsep):
             full_path = os.path.join(path, exe)
             if os.access(full_path, os.X_OK):
