--- django/test/runner.py.orig	2026-07-20 15:49:14 UTC
+++ django/test/runner.py
@@ -1044,7 +1044,6 @@ class DiscoverRunner:
             "resultclass": self.get_resultclass(),
             "verbosity": self.verbosity,
             "buffer": self.buffer,
-            "durations": self.durations,
         }
         return kwargs
 
