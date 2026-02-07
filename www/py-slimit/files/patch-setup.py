--- setup.py.orig	2013-03-26 09:09:32.000000000 +0100
+++ setup.py	2014-08-01 21:18:22.838964037 +0200
@@ -52,6 +52,7 @@
     """,
     classifiers=filter(None, classifiers.split('\n')),
     long_description=read('README.rst') + '\n\n' + read('CHANGES'),
-    extras_require={'test': []}
+    extras_require={'test': []},
+    test_suite='slimit.tests',
     )
 
