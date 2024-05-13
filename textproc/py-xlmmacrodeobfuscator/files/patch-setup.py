--- setup.py.orig	2024-05-13 02:14:33 UTC
+++ setup.py
@@ -18,7 +18,7 @@ setup(
 }
 
 setup(
-    name="XLMMacroDeobfuscator",
+    name="xlmmacrodeobfuscator",
     version=__version__,
     author="Amirreza Niakanlahiji",
     author_email="aniak2@uis.edu",
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
