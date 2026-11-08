Description: Use importlib.util.find_spec() instead of pkgutil.find_loader(),
  removed in Python 3.14.
Issue ID: none
Changeset: none (fixed on upstream main, see vbuild/__init__.py)
TODO: Drop when a release after 0.8.2 appears.

--- vbuild/__init__.py.orig	2023-08-03 09:26:18 UTC
+++ vbuild/__init__.py
@@ -9,7 +9,7 @@
 # #############################################################################
 __version__ = "0.8.2" # auto-updated
 
-import re, os, json, glob, itertools, traceback, subprocess, pkgutil
+import re, os, json, glob, itertools, traceback, subprocess, importlib.util
 
 try:
     from HTMLParser import HTMLParser
@@ -30,9 +30,9 @@ fullPyComp = True  # 3 states ;-)
 # False : minimal py comp, vbuild will include the std lib
 # True  : each component generate its needs (default)
 
-hasLess = bool(pkgutil.find_loader("lesscpy"))
-hasSass = bool(pkgutil.find_loader("scss"))
-hasClosure = bool(pkgutil.find_loader("closure"))
+hasLess = bool(importlib.util.find_spec("lesscpy"))
+hasSass = bool(importlib.util.find_spec("scss"))
+hasClosure = bool(importlib.util.find_spec("closure"))
 
 
 class VBuildException(Exception):
