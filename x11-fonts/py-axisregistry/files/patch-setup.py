--- setup.py.orig	2023-01-11 17:08:40 UTC
+++ setup.py
@@ -46,5 +46,5 @@ setup(
         "setuptools>=61.2",
         "setuptools_scm[toml]>=6.2",
     ],
-    install_requires=["protobuf>=3.19.4, <4", "fonttools"],
+    install_requires=["protobuf>=3.19.4", "fonttools"],
 )
