--- src/supervisor/options.py.orig	2010-08-14 02:34:50.000000000 +0800
+++ src/supervisor/options.py	2010-11-23 02:33:20.000000000 +0800
@@ -105,10 +105,7 @@
     def default_configfile(self):
         """Return the name of the found config file or raise. """
         here = os.path.dirname(os.path.dirname(sys.argv[0]))
-        paths = [os.path.join(here, 'etc', 'supervisord.conf'),
-                 os.path.join(here, 'supervisord.conf'),
-                 'supervisord.conf', 'etc/supervisord.conf',
-                 '/etc/supervisord.conf']
+        paths = [ '%%PREFIX%%/etc/supervisord.conf' ]
         config = None
         for path in paths:
             if os.path.exists(path):
