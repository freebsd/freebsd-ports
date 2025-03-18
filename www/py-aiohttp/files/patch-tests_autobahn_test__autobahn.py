--- tests/autobahn/test_autobahn.py.orig	2025-02-24 15:18:07 UTC
+++ tests/autobahn/test_autobahn.py
@@ -5,7 +5,7 @@ import pytest
 from typing import Any, Dict, Generator, List
 
 import pytest
-import python_on_whales
+python_on_whales = pytest.importorskip("python_on_whales")
 from pytest import TempPathFactory
 
 
