-- Skip the /dev/shm disk-space check on FreeBSD.
-- On FreeBSD /dev/shm is part of devfs, so shutil.disk_usage() reports
-- the devfs size rather than the actual POSIX shared-memory capacity.
-- This caused vLLM to fail with "Insufficient space in /dev/shm" even
-- though enough shared memory was available.
-- This is a FreeBSD port-specific workaround.

--- vllm/distributed/device_communicators/shm_broadcast.py.orig	2026-11-02 08:07:02 UTC
+++ vllm/distributed/device_communicators/shm_broadcast.py
@@ -258,7 +258,14 @@ def check_shm_free_space(
     """
     if os.path.isdir(shm_path):
-        free_bytes = shutil.disk_usage(shm_path).free
+        if sys.platform.startswith("freebsd"):
+            # On FreeBSD /dev/shm is part of devfs, so
+            # shutil.disk_usage() does not reflect the actual
+            # POSIX shared-memory capacity. Rely on the cgroup
+            # memory check below instead.
+            free_bytes = float("inf")
+        else:
+            free_bytes = shutil.disk_usage(shm_path).free
         if required_bytes > free_bytes:
             mib = 1 << 20
             raise RuntimeError(
