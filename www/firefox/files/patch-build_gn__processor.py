commit f45598b3294cc98c4b1f446aebbe0bdb1e5f5d75
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    FreeBSD workings for webrtc configure (gn_processor.py)

diff --git build/gn_processor.py build/gn_processor.py
index 9d04c760f1e9..e091524a3fa2 100644
--- build/gn_processor.py
+++ build/gn_processor.py
@@ -215,6 +215,7 @@ def filter_gn_config(path, gn_result, sandbox_vars, input_vars, gn_target):
     }
     oses = {
         "android": "Android",
+        "freebsd": "FreeBSD",
         "linux": "Linux",
         "mac": "Darwin",
         "ios": "Darwin",
@@ -1063,17 +1064,17 @@ def generate_gn_configs(topsrcdir, config):
 
     vars_set = []
     for is_debug in (True, False):
-        for target_os in ("android", "ios", "linux", "mac", "openbsd", "win"):
+        for target_os in ("freebsd",):
             target_cpus = ["x64"]
-            if target_os in ("android", "ios", "linux", "mac", "win", "openbsd"):
+            if target_os in ("android", "freebsd", "ios", "linux", "mac", "win", "openbsd"):
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
@@ -1087,7 +1088,7 @@ def generate_gn_configs(topsrcdir, config):
                 vars.update(config_args.get("*", {}))
                 vars.update(config_args.get(target_os, {}))
 
-                if target_os == "linux":
+                if target_os in ("freebsd", "linux"):
                     for enable_x11 in (True, False):
                         vars["ozone_platform_x11"] = enable_x11
                         vars_set.append(vars.copy())
