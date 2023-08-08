--- setup.py.orig	2022-10-03 07:48:40 UTC
+++ setup.py
@@ -35,9 +35,9 @@ setup(
     python_requires='>=3.4',
     install_requires=[
         "pyxlsb2",
-        "lark-parser",
+        "lark",
         "xlrd2",
-        "untangle==1.2.1",
+        "untangle>=1.2.1",
         "msoffcrypto-tool",
         "roman"
     ],
