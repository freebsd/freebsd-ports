--- /dev/null
+++ conftest.py
@@ -0,0 +1,11 @@
+import sys
+
+import pytest
+
+
+@pytest.fixture
+def backup_and_restore_sys_argv():
+    old_argv = sys.argv
+    sys.argv = sys.argv.copy()
+    yield
+    sys.argv = old_argv
