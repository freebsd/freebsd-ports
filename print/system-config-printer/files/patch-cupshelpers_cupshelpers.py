--- cupshelpers/cupshelpers.py.orig	2008-07-09 06:23:44.000000000 -0500
+++ cupshelpers/cupshelpers.py	2008-07-26 13:33:50.596144479 -0500
@@ -20,7 +20,7 @@
 
 import cups, pprint, os, tempfile, re
 import locale
-from . import _debugprint
+# from . import _debugprint
 
 class Printer:
     _flags_blacklist = ["options", "local"]
@@ -699,7 +699,7 @@
 
     # First, a local function.  How to check that something exists
     # in a path:
-    def pathcheck (name, path="/usr/bin:/bin"):
+    def pathcheck (name, path="%%LOCALBASE%%/bin:/usr/bin:/bin:%%PREFIX%%/bin"):
         # Strip out foomatic '%'-style place-holders.
         p = name.find ('%')
         if p != -1:
@@ -794,7 +794,7 @@
                     continue
 
                 exepath = pathcheck (exe,
-                                     "/usr/lib/cups/filter:"
+                                     "%%LOCALBASE%%/libexec/cups/filter:"
                                      "/usr/lib64/cups/filter")
 
     if exe and not exepath:
