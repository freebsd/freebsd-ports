--- vllm/platforms/__init__.py.orig	2026-11-02 08:07:02 UTC
+++ vllm/platforms/__init__.py
@@ -190,11 +190,13 @@ def cpu_platform_plugin() -> str | None:
             if not is_cpu:
                 import sys
 
-                is_cpu = sys.platform.startswith("darwin")
+                is_cpu = sys.platform.startswith("darwin") or sys.platform.startswith(
+                    "freebsd"
+                )
                 if is_cpu:
                     logger.debug(
                         "Confirmed CPU platform is available because the machine "
-                        "is MacOS."
+                        "is MacOS or FreeBSD."
                     )
         except Exception as e:
             logger.debug("CPU platform is not available because: %s", str(e))
