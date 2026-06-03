-- Fix cylinder example path in demo test
-- This patch is needed to ensure tests pass on FreeBSD
--- tests/integration/tests/test_demo/test_suite.py.orig	2026-05-08 17:08:44 UTC
+++ tests/integration/tests/test_demo/test_suite.py
@@ -24,7 +24,7 @@ def test_demo(launcher_script, request, log_file, tmp_
 
     # Either specify a case, or load it here into a json, manipulate
     # and save a new case file.
-    case_file = join(neko_dir, "examples", "cylinder", "cylinder.case")
+    case_file = join(neko_dir, "tests", "integration", "tests", "test_cylinder", "cylinder_part1.case")
 
     # Read the case file. We use json5 to allow comments in the case file.
     with open(case_file, "r") as f:
