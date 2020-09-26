--- src/htmlparser/fsm_config.py.orig	2020-09-26 14:52:15 UTC
+++ src/htmlparser/fsm_config.py
@@ -210,7 +210,11 @@ class FSMConfig(object):
 
     self.sm['state'] = self.AddState
     self.sm['condition'] = self.AddCondition
-    execfile(filename, self.sm)
+
+    with open(filename) as f:
+        code = compile(f.read(), filename, 'exec')
+        exec(code, self.sm)
+
     self.name = self.sm['name']
     if not self.name.isalnum():
       raise Exception("State machine name must consist of only alphanumeric"
