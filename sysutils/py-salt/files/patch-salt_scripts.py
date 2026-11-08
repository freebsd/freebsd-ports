--- salt/scripts.py.orig	2026-10-26 21:57:12 UTC
+++ salt/scripts.py
@@ -34,7 +34,7 @@
 # would otherwise cause the pin to be skipped).  Operators who specifically
 # want the PEP-741 safety property can call ``set_start_method`` again with
 # their preferred value after Salt is imported.
-if sys.version_info >= (3, 14) and sys.platform.startswith("linux"):
+if sys.version_info >= (3, 14) and sys.platform.startswith(("linux", "freebsd")):
     multiprocessing.set_start_method("fork", force=True)
 
 
@@ -108,7 +108,7 @@
     jobs but never responding because their fork-spawned workers die
     invisibly). Idempotent on re-entry.
     """
-    if not sys.platform.startswith("linux"):
+    if not sys.platform.startswith(("linux", "freebsd")):
         return
     import multiprocessing
 
