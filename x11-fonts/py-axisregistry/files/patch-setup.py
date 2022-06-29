--- setup.py.orig	2022-06-23 17:45:59 UTC
+++ setup.py
@@ -42,6 +42,6 @@ setup(
         "Programming Language :: Python :: 3",
     ],
     python_requires=">=3.7",
-    setup_requires=["setuptools_scm>=4,<6.1"],
+    setup_requires=["setuptools_scm>=4"],
     install_requires=["protobuf"],
 )
