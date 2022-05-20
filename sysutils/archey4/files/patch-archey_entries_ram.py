--- archey/entries/ram.py.orig	2022-02-08 18:10:31 UTC
+++ archey/entries/ram.py
@@ -1,5 +1,6 @@
 """RAM usage detection class"""
 
+import os
 import platform
 import re
 
@@ -38,6 +39,9 @@ class RAM(Entry):
         if platform.system() == 'Linux':
             with suppress(IndexError, FileNotFoundError):
                 return self._run_free_dash_m()
+        elif platform.system() == 'FreeBSD':
+            with suppress(FileNotFoundError):
+                return self._run_sysctl_mem()
         else:
             # Darwin or any other BSD-based system.
             with suppress(FileNotFoundError):
@@ -122,6 +126,26 @@ class RAM(Entry):
         ) * page_size
 
         return (used / 1024**2), (total / 1024**2)
+
+    @staticmethod
+    def _run_sysctl_mem() -> Tuple[float, float]:
+        """
+        Return used and total memory on FreeBSD
+        """
+        output = check_output(
+                ['sysctl', '-n', 'vm.stats.vm.v_page_count',
+                                 'vm.stats.vm.v_free_count',
+                                 'vm.stats.vm.v_inactive_count'],
+                universal_newlines=True
+        )
+        total, free, inactive = [float(x) for x in output.splitlines()]
+
+        page_size = os.sysconf(os.sysconf_names['SC_PAGESIZE'])
+
+        mem_total = total * (page_size >> 10)
+        mem_used = (total - free - inactive) * (page_size >> 10)
+
+        return (mem_used / 1024), (mem_total / 1024)
 
 
     def output(self, output):
