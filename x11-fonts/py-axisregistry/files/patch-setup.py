--- setup.py.orig	2022-10-27 13:57:55 UTC
+++ setup.py
@@ -42,6 +42,6 @@ setup(
         "Programming Language :: Python :: 3",
     ],
     python_requires=">=3.7",
-    setup_requires=["setuptools_scm>=4,<6.1"],
+    setup_requires=["setuptools_scm>=4"],
     install_requires=["protobuf>=3.19.4", "fonttools"],
 )
