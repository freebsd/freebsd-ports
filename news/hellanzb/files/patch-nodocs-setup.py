--- setup.py.bak	2006-03-26 22:14:40.000000000 -0800
+++ setup.py	2006-03-26 22:15:05.000000000 -0800
@@ -40,8 +40,7 @@
         packages = [ 'Hellanzb', 'Hellanzb.NZBLeecher', 'Hellanzb.HellaXMLRPC',
                      'Hellanzb.external', 'Hellanzb.external.elementtree' ],
         scripts = [ 'hellanzb.py' ],
-        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ),
-                       ( 'share/doc/hellanzb', [ 'CHANGELOG', 'CREDITS', 'README', 'LICENSE' ] ) ],
+        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ), ],
 
         # py2app options
         app = [ 'hellanzb.py' ],
