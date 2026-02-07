--- tests/test_metadata.py.orig	2023-11-30 00:16:36 UTC
+++ tests/test_metadata.py
@@ -57,10 +57,10 @@ def test_required_python_version():
     Make sure that the Python interpreter we're running this test suite on
     falls into the required Python range.
     """
-    with open("Cargo.toml", encoding="utf-8") as f:
-        cargo_toml = toml.loads(f.read())
+    with open("pyproject.toml", encoding="utf-8") as f:
+        pyproject_toml = toml.loads(f.read())

-    required_python = cargo_toml["package"]["metadata"]["maturin"]["requires-python"]
+    required_python = pyproject_toml["project"]["requires-python"]
     assert required_python.startswith(">=")
     required_python = required_python[2:]
     assert get_current_python_version() >= parse_version(required_python)
