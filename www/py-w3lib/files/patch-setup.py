--- ./setup.py.orig	2013-11-09 12:00:10.000000000 +0400
+++ ./setup.py	2013-11-10 22:16:19.000000000 +0400
@@ -24,4 +24,5 @@
         'Topic :: Internet :: WWW/HTTP',
     ],
     install_requires=['six >= 1.4.1'],
+    zip_safe = False,
 )
