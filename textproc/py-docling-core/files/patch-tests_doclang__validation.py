-- Make DocLang XML validation a no-op/skip when the optional saxonche schematron
-- backend is not available. This backend is not packaged for FreeBSD yet.
--- tests/doclang_validation.py.orig	2026-10-31 02:04:43 UTC
+++ tests/doclang_validation.py
@@ -76,6 +76,14 @@ xfail_invalid_dclg_xml = pytest.mark.xfail(
 )
 
 
+def _skip_if_backend_missing() -> None:
+    """Skip the current test when the doclang schematron backend is unavailable."""
+    if doclang_validate is None:
+        pytest.skip("reference doclang package not installed")
+    if saxonche is None:
+        pytest.skip("doclang/schematron-saxon backend not installed")
+
+
 def assert_valid_dclg_xml(
     xml_text: str,
     *,
