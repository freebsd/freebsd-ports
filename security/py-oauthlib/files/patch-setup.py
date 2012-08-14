--- ./setup.py.orig	2012-08-14 19:04:25.000000000 +1000
+++ ./setup.py	2012-08-14 19:04:38.000000000 +1000
@@ -32,4 +32,5 @@
     tests_require=tests_require,
     extras_require={'test': tests_require, 'rsa': rsa_require},
     install_requires=requires,
+    zip_safe=False,
 )
