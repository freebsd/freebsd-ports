--- setup.py.orig	2017-12-24 15:32:10 UTC
+++ setup.py
@@ -112,7 +112,9 @@ params.update({
                  'pysmi.parser',
                  'pysmi.codegen',
                  'pysmi.borrower',
-                 'pysmi.writer'],
+                 'pysmi.writer',
+                 'pysmi.tests',
+    ],
     'scripts': [os.path.join('scripts', 'mibdump.py')]
 })
 
