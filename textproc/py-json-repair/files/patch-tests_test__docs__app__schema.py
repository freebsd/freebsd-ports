--  Skip tests that require flask_cors if it is not installed.
--  The docs demo app requires flask_cors which is not a mandatory dependency.

--- tests/test_docs_app_schema.py.orig	2026-06-03 00:36:06 UTC
+++ tests/test_docs_app_schema.py
@@ -1,6 +1,7 @@ pytest.importorskip("flask")
 import pytest
 
 pytest.importorskip("flask")
+pytest.importorskip("flask_cors")
 
 from docs.app import app
 
