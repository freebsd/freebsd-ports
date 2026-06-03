--- setup.py.orig	2026-04-07 17:26:12 UTC
+++ setup.py
@@ -42,7 +42,11 @@ if sys.platform.startswith("darwin") and VLLM_TARGET_D
 if sys.platform.startswith("darwin") and VLLM_TARGET_DEVICE != "cpu":
     logger.warning("VLLM_TARGET_DEVICE automatically set to `cpu` due to macOS")
     VLLM_TARGET_DEVICE = "cpu"
-elif not (sys.platform.startswith("linux") or sys.platform.startswith("darwin")):
+elif not (
+    sys.platform.startswith("linux")
+    or sys.platform.startswith("darwin")
+    or sys.platform.startswith("freebsd")
+):
     logger.warning(
         "vLLM only supports Linux platform (including WSL) and MacOS."
         "Building on %s, "
