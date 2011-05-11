diff -r 8b9fbf3bcff6 -r 302bc22ed16c sa/sae.py
--- sa/sae.py.orig
+++ sa/sae.py
@@ -548,7 +548,8 @@
         Launch a script
         """
         def script_callback(transaction, response=None, error=None):
-            stream.current_scripts -= 1
+            if stream is not None:
+                stream.current_scripts -= 1
             if object.profile_name != "NOC.SAE":
                 try:
                     self.object_scripts[object.id] -= 1
@@ -564,6 +565,7 @@
             callback(result=result)
         
         logging.info("script %s(%s)" % (script_name, object))
+        stream = None
         if object.profile_name != "NOC.SAE":
             # Validate activator is present
             try:
