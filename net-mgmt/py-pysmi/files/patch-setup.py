--- setup.py.orig	2015-11-07 19:23:39 UTC
+++ setup.py
@@ -80,7 +80,8 @@ params.update( {
                   'pysmi.parser',
                   'pysmi.codegen',
                   'pysmi.borrower',
-                  'pysmi.writer' ],
+                  'pysmi.writer',
+                  'pysmi.tests' ],
     'scripts': [ os.path.join('scripts','mibdump.py') ]
 } )
 
