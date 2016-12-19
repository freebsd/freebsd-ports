--- setup.py.orig	2016-08-23 16:28:28 UTC
+++ setup.py
@@ -419,9 +419,6 @@ def doSetup():
         scripts=[
             "bin/caldavd",
         ],
-        data_files=[
-            ("caldavd", ["conf/caldavd.plist"]),
-        ],
         ext_modules=extensions,
         py_modules=[],
         setup_requires=setup_requirements,
