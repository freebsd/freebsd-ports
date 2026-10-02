--- build/toolchain/get_concurrent_links.py.orig	2026-09-13 16:54:58 UTC
+++ build/toolchain/get_concurrent_links.py
@@ -116,6 +116,11 @@ def _GetTotalMemoryInBytes(explanation):
             return int(subprocess.check_output(['sysctl', '-n', 'hw.memsize']))
         except Exception:
             return 0
+    elif sys.platform.startswith('freebsd'):
+        try:
+            return int(subprocess.check_output(['sysctl', '-n', 'hw.physmem']))
+        except Exception:
+            return 0
     # TODO(scottmg): Implement this for other platforms.
     return 0
 
