--- setup.py.orig	2026-04-22 12:28:05 UTC
+++ setup.py
@@ -118,7 +118,7 @@ class BuildCommand(build):
   def initialize_options(self):
 
     build.initialize_options(self)
-    self.dynamic_linking = None
+    self.dynamic_linking = True
     self.enable_magic = None
     self.enable_cuckoo = None
     self.enable_dex = None
