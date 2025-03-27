commit e884ff2873b6ef8f3c8ee0a09e7651f46b3add95
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    chase gn_processor.py move

diff --git build/gn_processor.py build/gn_processor.py
index 2ba8b92c27..962479b228 100644
--- build/gn_processor.py
+++ build/gn_processor.py
@@ -186,6 +186,7 @@ def filter_gn_config(path, gn_result, sandbox_vars, input_vars, gn_target):
     }
     oses = {
         "android": "Android",
+        "freebsd": "FreeBSD",
         "linux": "Linux",
         "mac": "Darwin",
         "openbsd": "OpenBSD",
@@ -780,17 +781,17 @@ def main():
 
     vars_set = []
     for is_debug in (True, False):
-        for target_os in ("android", "linux", "mac", "openbsd", "win"):
+        for target_os in ("freebsd",):
             target_cpus = ["x64"]
-            if target_os in ("android", "linux", "mac", "win", "openbsd"):
+            if target_os in ("android", "freebsd", "linux", "mac", "win", "openbsd"):
                 target_cpus.append("arm64")
             if target_os in ("android", "linux"):
                 target_cpus.append("arm")
-            if target_os in ("android", "linux", "win"):
+            if target_os in ("android", "freebsd", "linux", "win"):
                 target_cpus.append("x86")
-            if target_os in ("linux", "openbsd"):
+            if target_os in ("linux", "freebsd", "openbsd"):
                 target_cpus.append("riscv64")
-            if target_os == "linux":
+            if target_os in ("freebsd", "linux"):
                 target_cpus.extend(["loong64", "ppc64", "mipsel", "mips64el"])
             for target_cpu in target_cpus:
                 vars = {
@@ -799,7 +800,7 @@ def main():
                     "target_cpu": target_cpu,
                     "target_os": target_os,
                 }
-                if target_os == "linux":
+                if target_os in ("freebsd", "linux"):
                     for use_x11 in (True, False):
                         vars["use_x11"] = use_x11
                         vars_set.append(vars.copy())
