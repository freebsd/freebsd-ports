--- src/lib/LookupManager.py.orig	Thu Jul 15 15:15:58 2004
+++ src/lib/LookupManager.py	Mon Aug 16 22:20:25 2004
@@ -5,9 +5,9 @@
 import Config
 try:
     import adns, ADNS
-    _have_adns = True
+    _have_adns = False
 except ImportError:
-    error.log("No ADNS library found, using synchronous name lookups.")
+#    error.log("No ADNS library found, using synchronous name lookups.")
     _have_adns = False
 
 MAX_TIMES = 3
