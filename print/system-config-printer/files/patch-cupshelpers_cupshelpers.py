--- cupshelpers/cupshelpers.py.orig	2013-07-22 15:58:32.000000000 +0200
+++ cupshelpers/cupshelpers.py	2013-08-29 11:18:44.000000000 +0200
@@ -739,7 +739,7 @@
 
     # First, a local function.  How to check that something exists
     # in a path:
-    def pathcheck (name, path="/usr/bin:/bin"):
+    def pathcheck (name, path="%%LOCALBASE%%/bin:%%PREFIX%%/bin:/usr/bin:/bin"):
         if name == "-":
             # A filter of "-" means that no filter is required,
             # i.e. the device accepts the given format as-is.
