--- python/mozbuild/mozbuild/gn_processor.py.orig	2022-11-03 22:19:40.000000000 +0100
+++ python/mozbuild/mozbuild/gn_processor.py	2022-11-07 21:11:42.596355000 +0100
@@ -166,6 +166,7 @@
     }
     oses = {
         "android": "Android",
+        "freebsd": "FreeBSD",
         "linux": "Linux",
         "mac": "Darwin",
         "openbsd": "OpenBSD",
@@ -662,15 +663,15 @@
 
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
+            if target_os in ("freebsd", "linux"):
                 target_cpus.append("ppc64")
             for target_cpu in target_cpus:
                 vars = {
@@ -679,7 +680,7 @@
                     "target_cpu": target_cpu,
                     "target_os": target_os,
                 }
-                if target_os == "linux":
+                if target_os in ("freebsd", "linux"):
                     for use_x11 in (True, False):
                         vars["use_x11"] = use_x11
                         vars_set.append(vars.copy())
