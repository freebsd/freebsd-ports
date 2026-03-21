--- tests/tests.py.orig2026-03-14 18:12:00 UTC
+++ tests/tests.py
@@ -431,7 +431,7 @@ def print_info():
     print("  smt_args() = {}".format(smt_args()))
 
 
-def parse_test_options(
+def _parse_test_options(
     src, debug=False, multithreaded=False, xml=False
 ):  # pylint:disable=unused-argument
     """
@@ -1104,7 +1104,7 @@ def test_murphi2c(model):
     """test cases for murphi2c"""
 
     testcase = Path(__file__).parent / model
-    tweaks = dict(parse_test_options(testcase))
+    tweaks = dict(_parse_test_options(testcase))
 
     # there is no C equivalent of isundefined, because an implicit assumption in the C
     # representation is that you do not rely on undefined values
@@ -1151,7 +1151,7 @@ def test_murphi2c_header(model, tmp_path):
     """test cases for murphi2c --header"""
 
     testcase = Path(__file__).parent / model
-    tweaks = dict(parse_test_options(testcase))
+    tweaks = dict(_parse_test_options(testcase))
 
     # there is no C equivalent of isundefined, because an implicit assumption in the C
     # representation is that you do not rely on undefined values
@@ -1216,7 +1216,7 @@ def test_murphi2xml(model):
     """test cases for murphi2xml"""
 
     testcase = Path(__file__).parent / model
-    tweaks = dict(parse_test_options(testcase))
+    tweaks = dict(_parse_test_options(testcase))
 
     args = ["murphi2xml", "--", testcase]
     if has_valgrind():
@@ -1257,7 +1257,7 @@ def test_murphi2uclid(model, tmp_path):
     """test cases for murphi2uclid"""
 
     testcase = Path(__file__).parent / model
-    tweaks = dict(parse_test_options(testcase))
+    tweaks = dict(_parse_test_options(testcase))
 
     # test cases for which murphi2uclid is expected to fail
     murphi2uclid_fail = (
@@ -1429,7 +1429,7 @@ def test_rumur(model, multithreaded, mode, optimised)
     testcase = Path(__file__).parent / model
     debug = mode == "debug"
     xml = mode == "XML"
-    tweaks = dict(parse_test_options(testcase, debug, multithreaded, xml))
+    tweaks = dict(_parse_test_options(testcase, debug, multithreaded, xml))
 
     if tweaks.get("skip_reason") is not None:
         pytest.skip(tweaks["skip_reason"])
