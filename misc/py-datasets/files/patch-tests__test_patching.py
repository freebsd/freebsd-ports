-- This patch adds tests/_test_patching.py which is missing from the PyPI source distribution.
-- The file is taken from the GitHub repository at the same version tag.
-- Without this file, the test suite cannot be run.
--- /dev/null
+++ tests/_test_patching.py
@@ -0,0 +1,11 @@
+# ruff: noqa: F401
+# This is the module that test_patching.py uses to test patch_submodule()
+import os
+import os as renamed_os
+from os import path
+from os import path as renamed_path
+from os.path import join
+from os.path import join as renamed_join
+
+
+open = open  # we just need to have a builtin inside this module to test it properly
