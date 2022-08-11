--- archey/entries/cpu.py.orig	2022-05-17 20:52:34 UTC
+++ archey/entries/cpu.py
@@ -47,7 +47,7 @@ class CPU(Entry):
         else:
             # Darwin or any other BSD-based system.
             self.value = self._parse_system_profiler() or \
-                self._parse_sysctl_machdep()
+                self._parse_sysctl_machdep() or self._parse_sysctl_cpu_model()
 
         if not self.value:
             # This test case has been built for some ARM architectures (see #29).
@@ -157,6 +157,24 @@ class CPU(Entry):
                 [
                     'sysctl', '-n',
                     'machdep.cpu.brand_string', 'machdep.cpu.core_count'
+                ],
+                stderr=DEVNULL, universal_newlines=True
+            )
+        except (FileNotFoundError, CalledProcessError):
+            return []
+
+        # `sysctl_output` should exactly contains two lines.
+        model_name, nb_cores = sysctl_output.splitlines()
+        return [{model_name: int(nb_cores)}]
+
+    @staticmethod
+    def _parse_sysctl_cpu_model() -> List[Dict[str, int]]:
+        # Runs `sysctl` to fetch some `hw.model and hw.ncpu` keys.
+        try:
+            sysctl_output = check_output(
+                [
+                    'sysctl', '-n',
+                    'hw.model', 'hw.ncpu'
                 ],
                 stderr=DEVNULL, universal_newlines=True
             )
