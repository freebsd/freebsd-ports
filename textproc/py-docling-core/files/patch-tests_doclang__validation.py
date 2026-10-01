-- Make DocLang XML validation a no-op/skip when the optional saxonche schematron
-- backend is not available. This backend is not packaged for FreeBSD yet.
--- tests/doclang_validation.py.orig	2026-10-01 04:16:39 UTC
+++ tests/doclang_validation.py
@@ -16,15 +16,25 @@ except ImportError:
     doclang_validate = None  # type: ignore[assignment,misc]
     ValidationError = Exception  # type: ignore[misc,assignment]
 
+try:
+    import saxonche
+except ImportError:
+    saxonche = None  # type: ignore[assignment,misc]
 
+try:
+    from doclang.schematron import SchematronBackendNotFound
+except ImportError:
+    SchematronBackendNotFound = None  # type: ignore[assignment,misc]
+
+
 def doclang_validator_available() -> bool:
-    """Return True when the reference ``doclang`` package is importable."""
-    return doclang_validate is not None
+    """Return True when doclang and its schematron backend are available."""
+    return doclang_validate is not None and saxonche is not None
 
 
 doclang_validator = pytest.mark.skipif(
     not doclang_validator_available(),
-    reason="reference doclang package not installed (uv sync --extra doclang-validation)",
+    reason="doclang/schematron-saxon backend not installed (uv sync --extra doclang-validation)",
 )
 
 xfail_invalid_dclg_xml = pytest.mark.xfail(
@@ -52,18 +62,31 @@ def assert_valid_dclg_xml(
         path = tmp.name
     try:
         doclang_validate(path, allow_empty_namespace=allow_empty_namespace)
+    except Exception as exc:
+        if SchematronBackendNotFound is not None and isinstance(
+            exc, SchematronBackendNotFound
+        ):
+            return
+        raise
     finally:
         os.unlink(path)
 
 
+def _skip_if_backend_missing() -> None:
+    """Skip the current test when the doclang schematron backend is unavailable."""
+    if doclang_validate is None:
+        pytest.skip("reference doclang package not installed")
+    if saxonche is None:
+        pytest.skip("doclang/schematron-saxon backend not installed")
+
+
 def validate_dclg_xml(
     xml_text: str,
     *,
     allow_empty_namespace: bool = True,
 ) -> None:
     """Validate DocLang XML text; raises on failure when validator is available."""
-    if doclang_validate is None:
-        pytest.skip("reference doclang package not installed")
+    _skip_if_backend_missing()
 
     with tempfile.NamedTemporaryFile(
         mode="w",
@@ -86,8 +109,7 @@ def validate_dclg_file(
     allow_empty_namespace: bool = True,
 ) -> None:
     """Validate a DocLang XML file path."""
-    if doclang_validate is None:
-        pytest.skip("reference doclang package not installed")
+    _skip_if_backend_missing()
     doclang_validate(Path(path), allow_empty_namespace=allow_empty_namespace)
 
 
@@ -97,7 +119,6 @@ def assert_invalid_dclg_xml(
     allow_empty_namespace: bool = True,
 ) -> None:
     """Assert DocLang XML is rejected by the reference validator (known bad output)."""
-    if doclang_validate is None:
-        pytest.skip("reference doclang package not installed")
+    _skip_if_backend_missing()
     with pytest.raises(ValidationError):
         validate_dclg_xml(xml_text, allow_empty_namespace=allow_empty_namespace)
