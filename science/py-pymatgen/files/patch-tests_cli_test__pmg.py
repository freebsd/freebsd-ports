--- tests/cli/test_pmg.py.orig	2026-04-20 06:22:40 UTC
+++ tests/cli/test_pmg.py
@@ -1,5 +1,6 @@ from __future__ import annotations
 from __future__ import annotations
 
+import os
 import textwrap
 
 import pytest
@@ -82,6 +83,8 @@ def test_pmg_view(monkeypatch):
 
 def test_pmg_view(monkeypatch):
     pytest.importorskip("vtk", reason="vtk is not available")
+    if not os.environ.get("DISPLAY"):
+        pytest.skip("No DISPLAY available for VTK rendering")
 
     called = {}
 
