--- python/mozbuild/mozbuild/gn_processor.py.orig	2022-07-16 21:13:05.389103000 +0200
+++ python/mozbuild/mozbuild/gn_processor.py	2022-07-16 21:15:28.755882000 +0200
@@ -652,15 +652,15 @@
 
     vars_set = []
     for is_debug in (True, False):
-        for target_os in ("android", "linux", "mac", "openbsd", "win"):
+        for target_os in ("android", "freebsd", "linux", "mac", "openbsd", "win"):
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
+            if target_os in ("freebsd", "linux"):
                 target_cpus.append("ppc64")
             for target_cpu in target_cpus:
                 vars = {
@@ -674,7 +674,7 @@
                         vars["use_x11"] = use_x11
                         vars_set.append(vars.copy())
                 else:
-                    if target_os == "openbsd":
+                    if target_os in ("freebsd", "openbsd"):
                         vars["use_x11"] = True
                     vars_set.append(vars)
 
