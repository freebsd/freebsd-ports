--- vllm/platforms/cpu.py.orig	2026-11-02 08:07:03 UTC
+++ vllm/platforms/cpu.py
@@ -99,7 +99,7 @@ def get_max_threads(pid=0):
 def get_max_threads(pid=0):
     if hasattr(os, "sched_getaffinity"):
         return len(os.sched_getaffinity(pid))
-    elif platform.system() == "Darwin":
+    elif platform.system() in ("Darwin", "FreeBSD"):
         return os.cpu_count()
     else:
         raise NotImplementedError("Unsupported OS")
@@ -110,7 +110,8 @@ class CpuPlatform(Platform):
     device_name: str = "cpu"
     device_type: str = "cpu"
     dispatch_key: str = "CPU"
-    dist_backend: str = "gloo"
+    # FreeBSD lacks gloo TCP transport (epoll-based); use fake backend.
+    dist_backend: str = "fake" if sys.platform.startswith("freebsd") else "gloo"
     device_control_env_var = DEVICE_CONTROL_ENV_VAR
 
     @property
