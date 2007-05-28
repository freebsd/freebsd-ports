--- src/lib/LookupManager.py	Sat Feb 18 16:11:38 2006
+++ src/lib/LookupManager.py	Sun May 20 09:51:00 2007
@@ -26,7 +26,7 @@
 import Config
 try:
     import adns, ADNS
-    _have_adns = True
+    _have_adns = False
 except ImportError:
     error.log("No ADNS library found, using synchronous name lookups.")
     _have_adns = False
