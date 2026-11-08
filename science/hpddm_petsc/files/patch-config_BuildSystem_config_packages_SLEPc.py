--- config/BuildSystem/config/packages/SLEPc.py.orig	2026-09-29 03:42:55 UTC
+++ config/BuildSystem/config/packages/SLEPc.py
@@ -12,6 +12,7 @@ class Configure(config.package.Package):
     self.useddirectly           = 0
     self.linkedbypetsc          = 0
     self.builtafterpetsc        = 1
+    self.PrefixWriteCheck       = 0
     return
 
   def setupHelp(self, help):
