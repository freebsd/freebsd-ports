commit bcf74d8c7a315c4f8ef70f1a60d4ce957cebac1d
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    FreeBSD workings for webrtc configure (gn_processor.py)

diff --git build/gn_processor.py build/gn_processor.py
index 36cc6bdfe492..ed0fb2b7aa45 100644
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
@@ -801,17 +802,17 @@ def main():
 
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
+            if target_os in ("freebsd", "linux", "openbsd"):
                 target_cpus.append("riscv64")
-            if target_os == "linux":
+            if target_os in ("freebsd", "linux"):
                 target_cpus.extend(["loong64", "ppc64", "mipsel", "mips64el"])
             for target_cpu in target_cpus:
                 vars = {
@@ -820,7 +821,7 @@ def main():
                     "target_cpu": target_cpu,
                     "target_os": target_os,
                 }
-                if target_os == "linux":
+                if target_os in ("freebsd", "linux"):
                     for enable_x11 in (True, False):
                         vars["ozone_platform_x11"] = enable_x11
                         vars_set.append(vars.copy())
