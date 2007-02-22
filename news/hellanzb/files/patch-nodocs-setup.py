--- setup.py.orig	Mon Feb 19 18:12:55 2007
+++ setup.py	Wed Feb 21 16:34:28 2007
@@ -38,8 +38,7 @@
         packages = [ 'Hellanzb', 'Hellanzb.NZBLeecher', 'Hellanzb.HellaXMLRPC',
                      'Hellanzb.external', 'Hellanzb.external.elementtree' ],
         scripts = [ 'hellanzb.py' ],
-        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ),
-                       ( 'share/doc/hellanzb', [ 'CHANGELOG', 'CREDITS', 'README', 'LICENSE' ] ) ],
+        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ), ],
         )
     py2app_options = dict(
         app = [ 'hellanzb.py' ],
