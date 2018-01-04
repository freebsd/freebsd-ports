--- setup.py.orig	2017-08-27 16:10:56.170135000 -0400
+++ setup.py	2017-08-27 16:11:54.314120000 -0400
@@ -306,7 +306,7 @@
 install_requirements = [
     # Core frameworks
     "zope.interface",
-    "Twisted==16.6.0",
+    "Twisted>=16.6.0",
     "twextpy",
 
     # Security frameworks
@@ -416,9 +416,6 @@
         scripts=[
             "bin/caldavd",
         ],
-        data_files=[
-            ("caldavd", ["conf/caldavd.plist"]),
-        ],
         ext_modules=extensions,
         py_modules=[],
         setup_requires=setup_requirements,
