--- conftest.py.orig	2026-07-22 21:48:17 UTC
+++ conftest.py
@@ -14,6 +14,14 @@ import sys
 import os
 import sys
 
+# The deprecated pynvml package installs a meta path finder whose
+# find_spec() signature is incompatible with Python 3.12 and breaks
+# cirq import when pynvml happens to be present in the test environment.
+for _finder in sys.meta_path[:]:
+    if type(_finder).__name__ == "PynvmlFinder":
+        sys.meta_path.remove(_finder)
+del _finder
+
 # Ensure src/ is in sys.path so that the OpenFermion utils module can be
 # imported at Pytest startup time.
 sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "src")))
