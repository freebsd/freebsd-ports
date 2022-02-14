--- test/mitmproxy/platform/test_pf.py.orig	2021-09-28 16:43:29 UTC
+++ test/mitmproxy/platform/test_pf.py
@@ -2,14 +2,11 @@ import sys
 import pytest
 from mitmproxy.platform import pf
 
-
+@pytest.mark.skip
 class TestLookup:
 
     def test_simple(self, tdata):
-        if sys.platform == "freebsd10":
-            p = tdata.path("mitmproxy/data/pf02")
-        else:
-            p = tdata.path("mitmproxy/data/pf01")
+        p = tdata.path("mitmproxy/data/pf01")
         with open(p, "rb") as f:
             d = f.read()
 
