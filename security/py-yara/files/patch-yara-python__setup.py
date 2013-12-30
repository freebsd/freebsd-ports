--- ./yara-python/setup.py.orig	2013-12-29 00:44:57.000000000 -0500
+++ ./yara-python/setup.py	2013-12-29 00:48:55.000000000 -0500
@@ -9,4 +9,5 @@
         sources=['yara-python.c'],
         libraries=['yara'],
         include_dirs=['../windows/include', '../libyara'],
+        library_dirs=['%%LOCALBASE%%/lib'],
     )])
