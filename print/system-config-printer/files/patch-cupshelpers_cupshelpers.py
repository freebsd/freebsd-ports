--- cupshelpers/cupshelpers.py.orig	2009-12-22 09:44:19.000000000 -0500
+++ cupshelpers/cupshelpers.py	2009-12-29 00:08:26.000000000 -0500
@@ -663,7 +663,7 @@
 
     # First, a local function.  How to check that something exists
     # in a path:
-    def pathcheck (name, path="/usr/bin:/bin"):
+    def pathcheck (name, path="%%LOCALBASE%%/bin:%%PREFIX%%/bin:/usr/bin:/bin"):
         if name == "-":
             # A filter of "-" means that no filter is required,
             # i.e. the device accepts the given format as-is.
@@ -765,7 +765,7 @@
                     continue
 
                 exepath = pathcheck (exe,
-                                     "/usr/lib/cups/filter:"
+                                     "%%LOCALBASE%%/libexec/cups/filter:"
                                      "/usr/lib64/cups/filter")
 
     if exe and not exepath:
