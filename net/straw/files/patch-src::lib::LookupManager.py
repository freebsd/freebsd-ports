--- src/lib/LookupManager.py.orig	Thu Nov 13 23:37:03 2003
+++ src/lib/LookupManager.py	Thu Nov 13 23:38:28 2003
@@ -6,9 +6,9 @@
 from error import log
 try:
     import adns, ADNS
-    _have_adns = True
+    _have_adns = False
 except ImportError:
-    log("No ADNS library found, using synchronous name lookups.")
+    #log("No ADNS library found, using synchronous name lookups.")
     _have_adns = False
 
 MAX_TIMES = 3
