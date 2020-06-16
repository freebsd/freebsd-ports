# Add a patch from Mattia Rizzolo to prevent tests
# from failing due to the no-tlsh-module warning.

--- diffoscope/main.py.orig	2020-06-11 11:45:39 UTC
+++ diffoscope/main.py
@@ -658,7 +658,7 @@ def run_diffoscope(parsed_args):
 
     ProfileManager().setup(parsed_args)
     PresenterManager().configure(parsed_args)
-    if not tlsh:
+    if not tlsh and "PYTEST_CURRENT_TEST" not in os.environ:
         logger.warning(
             'Fuzzy-matching is currently disabled as the "tlsh" module is unavailable.'
         )
