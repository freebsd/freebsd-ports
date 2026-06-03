--- django/test/runner.py.orig	2025-12-05 06:35:08 UTC
+++ django/test/runner.py
@@ -1057,7 +1057,6 @@ class DiscoverRunner:
             "resultclass": self.get_resultclass(),
             "verbosity": self.verbosity,
             "buffer": self.buffer,
-            "durations": self.durations,
         }
         return kwargs
 
