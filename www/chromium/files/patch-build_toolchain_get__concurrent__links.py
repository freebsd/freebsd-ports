--- build/toolchain/get_concurrent_links.py.orig	2021-08-17 00:15:54 UTC
+++ build/toolchain/get_concurrent_links.py
@@ -53,6 +53,11 @@ def _GetTotalMemoryInBytes():
       return int(subprocess.check_output(['sysctl', '-n', 'hw.memsize']))
     except Exception:
       return 0
+  elif sys.platform.startswith('freebsd'):
+    try:
+      return int(subprocess.check_output(['sysctl', '-n', 'hw.physmem']))
+    except Exception:
+      return 1
   # TODO(scottmg): Implement this for other platforms.
   return 0
 
