--- vllm/platforms/__init__.py.orig	2026-05-09 20:28:19 UTC
+++ vllm/platforms/__init__.py
@@ -58,6 +58,11 @@ def cuda_platform_plugin() -> str | None:
 
 
 def cuda_platform_plugin() -> str | None:
+    import sys
+    if sys.platform.startswith("freebsd"):
+        # CUDA extensions are not built on FreeBSD; use CPU platform instead.
+        logger.debug("CUDA platform disabled on FreeBSD.")
+        return None
     is_cuda = False
     logger.debug("Checking if CUDA platform is available.")
     try:
@@ -172,10 +177,12 @@ def cpu_platform_plugin() -> str | None:
         if not is_cpu:
             import sys
 
-            is_cpu = sys.platform.startswith("darwin")
+            is_cpu = sys.platform.startswith("darwin") or sys.platform.startswith(
+                "freebsd"
+            )
             if is_cpu:
                 logger.debug(
-                    "Confirmed CPU platform is available because the machine is MacOS."
+                    "Confirmed CPU platform is available because the machine is MacOS or FreeBSD."
                 )
     except Exception as e:
         logger.debug("CPU platform is not available because: %s", str(e))
