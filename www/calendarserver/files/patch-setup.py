--- setup.py.orig	2016-01-07 15:18:44 UTC
+++ setup.py
@@ -429,9 +429,6 @@ def doSetup():
         scripts=[
             "bin/caldavd",
         ],
-        data_files=[
-            ("caldavd", ["conf/caldavd.plist"]),
-        ],
         ext_modules=extensions,
         py_modules=[],
         setup_requires=setup_requirements,
