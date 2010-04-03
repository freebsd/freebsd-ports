--- src/supervisor/options.py.orig	2010-02-11 13:25:24.000000000 +0300
+++ src/supervisor/options.py	2010-02-11 13:25:55.000000000 +0300
@@ -105,7 +105,7 @@
     def default_configfile(self):
         """Return the name of the found config file or raise. """
         paths = ['supervisord.conf', 'etc/supervisord.conf',
-                 '/etc/supervisord.conf']
+                 '/etc/supervisord.conf', '%%PREFIX%%/etc/supervisord.conf']
         config = None
         for path in paths:
             if os.path.exists(path):
