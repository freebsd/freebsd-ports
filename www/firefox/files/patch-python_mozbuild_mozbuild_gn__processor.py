diff --git python/mozbuild/mozbuild/gn_processor.py python/mozbuild/mozbuild/gn_processor.py
index a1b8367fc11b..fe1087270fc0 100644
--- python/mozbuild/mozbuild/gn_processor.py
+++ python/mozbuild/mozbuild/gn_processor.py
@@ -183,6 +183,7 @@ def filter_gn_config(path, gn_result, sandbox_vars, input_vars, gn_target):
     }
     oses = {
         "android": "Android",
+        "freebsd": "FreeBSD",
         "linux": "Linux",
         "mac": "Darwin",
         "openbsd": "OpenBSD",
@@ -733,16 +734,16 @@ def main():
 
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
-            if target_os == "linux":
-                target_cpus.extend(["ppc64", "riscv64"])
+            if target_os in ("freebsd", "linux"):
+                target_cpus.append("ppc64")
             for target_cpu in target_cpus:
                 vars = {
                     "host_cpu": "x64",
@@ -750,7 +751,7 @@ def main():
                     "target_cpu": target_cpu,
                     "target_os": target_os,
                 }
-                if target_os == "linux":
+                if target_os in ("freebsd", "linux"):
                     for use_x11 in (True, False):
                         vars["use_x11"] = use_x11
                         vars_set.append(vars.copy())
