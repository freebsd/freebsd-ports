--- ASTK_SERV/asrun/run.py.orig	2026-10-13 09:49:08 UTC
+++ ASTK_SERV/asrun/run.py
@@ -265,7 +265,7 @@ class AsterRun:
                      "Remove it from your configuration file." % key,
                      DeprecationWarning, stacklevel=2)
                 # remove display
-                self.config[key] = re.sub('\-+display[ =]+@D', '', value)
+                self.config[key] = re.sub(r'\-+display[ =]+@D', '', value)
 
 
     def _add_action(self, action, info):
