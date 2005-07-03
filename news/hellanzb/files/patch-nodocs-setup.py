--- setup.py.bak	Thu Jun 30 14:49:48 2005
+++ setup.py	Thu Jun 30 14:50:22 2005
@@ -35,8 +35,7 @@
 
         packages = [ 'Hellanzb', 'Hellanzb.NZBLeecher', 'Hellanzb.HellaXMLRPC' ],
         scripts = [ 'hellanzb.py' ],
-        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ),
-                       ( 'share/doc/hellanzb', [ 'CHANGELOG', 'CREDITS', 'README', 'LICENSE' ] ) ],
+        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ), ],
         )
 
 if __name__ == '__main__':
