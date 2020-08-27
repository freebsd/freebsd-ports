--- setup.py.orig	2019-05-11 09:18:35 UTC
+++ setup.py
@@ -32,12 +32,12 @@ setup(
     py_modules=["socks", "sockshandler"],
     install_requires=requirements,
     python_requires=">=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*",
-    classifiers=(
+    classifiers=[
         "Programming Language :: Python :: 2",
         "Programming Language :: Python :: 2.7",
         "Programming Language :: Python :: 3",
         "Programming Language :: Python :: 3.4",
         "Programming Language :: Python :: 3.5",
         "Programming Language :: Python :: 3.6",
-    ),
+    ],
 )
