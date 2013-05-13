--- ./setup.py.orig	2013-05-04 16:37:49.000000000 +1000
+++ ./setup.py	2013-05-04 17:04:12.135652732 +1000
@@ -43,6 +43,9 @@
         'Programming Language :: Python :: 2.6',
         'Programming Language :: Python :: 2.7',
     ),
+    zip_safe=False,
+    tests_require = ['mock'],
+    test_suite="tests",
 )
 
 
