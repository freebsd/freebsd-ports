--- setup.py.orig	2022-02-03 00:53:18 UTC
+++ setup.py
@@ -35,9 +35,9 @@ setup(
     python_requires='>=3.4',
     install_requires=[
         "pyxlsb2",
-        "lark-parser",
+        "lark",
         "xlrd2",
-        "untangle==1.1.1",
+        "untangle>=1.1.1",
         "msoffcrypto-tool",
         "roman"
     ],
