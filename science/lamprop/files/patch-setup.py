--- setup.py.orig	2020-12-29 15:45:52 UTC
+++ setup.py
@@ -81,7 +81,8 @@ def mkarchive(name, modules, main="__main__.py"):
         main: Name of the main file. Defaults to __main__.py
     """
     std = "__main__.py"
-    shebang = b"#!/usr/bin/env python\n"
+    with open(sys.argv[0], "rb") as f:
+        shebang = f.readline()
     if isinstance(modules, str):
         modules = [modules]
     if main != std:
