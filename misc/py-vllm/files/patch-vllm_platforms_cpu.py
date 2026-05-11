--- vllm/platforms/cpu.py.orig	2026-05-11 06:13:24 UTC
+++ vllm/platforms/cpu.py
@@ -44,7 +44,8 @@ class CpuPlatform(Platform):
     device_name: str = "cpu"
     device_type: str = "cpu"
     dispatch_key: str = "CPU"
-    dist_backend: str = "gloo"
+    # FreeBSD lacks gloo TCP transport (epoll-based); use fake backend.
+    dist_backend: str = "fake" if sys.platform.startswith("freebsd") else "gloo"
     device_control_env_var = DEVICE_CONTROL_ENV_VAR
 
     @property
