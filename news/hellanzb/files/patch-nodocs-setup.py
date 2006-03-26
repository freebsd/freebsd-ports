--- setup.py.bak	Thu Feb  9 20:21:21 2006
+++ setup.py	Thu Feb  9 20:21:58 2006
@@ -36,8 +36,7 @@
         packages = [ 'Hellanzb', 'Hellanzb.NZBLeecher', 'Hellanzb.HellaXMLRPC',
                      'Hellanzb.external', 'Hellanzb.external.elementtree' ],
         scripts = [ 'hellanzb.py' ],
-        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ),
-                       ( 'share/doc/hellanzb', [ 'CHANGELOG', 'CREDITS', 'README', 'LICENSE' ] ) ],
+        data_files = [ ( 'etc', [ 'etc/hellanzb.conf.sample' ] ), ],
         )
 
 if __name__ == '__main__':
