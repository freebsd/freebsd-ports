--- ./setup.py.orig	2013-10-14 22:33:04.000000000 +0400
+++ ./setup.py	2013-10-15 09:17:38.000000000 +0400
@@ -75,5 +75,7 @@
         'Topic :: Security :: Cryptography',
         ],
 
+    zip_safe=False,
+
     **args
 )
