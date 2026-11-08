--- third_party/xla/third_party/highwayhash/highwayhash.BUILD.orig	2026-03-04 22:33:50 UTC
+++ third_party/xla/third_party/highwayhash/highwayhash.BUILD
@@ -21,7 +21,7 @@
 
 config_setting(
     name = "cpu_ppc",
-    values = {"cpu": "ppc"},
+    constraint_values = ["@platforms//cpu:ppc"],
 )
 
 config_setting(
