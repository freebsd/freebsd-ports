--- setup.py.orig	2016-02-13 18:11:15 UTC
+++ setup.py
@@ -83,7 +83,9 @@ params.update({
                  'pysmi.parser',
                  'pysmi.codegen',
                  'pysmi.borrower',
-                 'pysmi.writer'],
+                 'pysmi.writer',
+                 'pysmi.tests',
+    ],
     'scripts': [os.path.join('scripts', 'mibdump.py')]
 })
 
