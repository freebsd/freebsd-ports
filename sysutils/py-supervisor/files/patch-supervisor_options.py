--- supervisor/options.py.orig	2012-01-10 12:55:20.000000000 +0300
+++ supervisor/options.py	2012-01-10 12:56:14.000000000 +0300
@@ -92,10 +92,7 @@
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
