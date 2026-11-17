-- Recognize FreeBSD using sys.platform.startswith() instead of an exact match.
-- sys.platform on FreeBSD includes the OS version (e.g. "freebsd15"), so
-- the previous check "sys.platform in (... 'freebsd')" never matched and
-- vLLM fell through to Linux-only code paths such as lscpu and /proc.
-- This is a FreeBSD port-specific workaround.

--- vllm/utils/cpu_resource_utils.py.orig	2026-11-02 08:07:03 UTC
+++ vllm/utils/cpu_resource_utils.py
@@ -160,14 +160,19 @@ def get_memory_affinity(pid: int = 0) -> list[int]:


 def get_memory_affinity(pid: int = 0) -> list[int]:
+    if sys.platform != "linux":
+        return []
     pid = os.getpid() if pid == 0 else pid
     path = f"/proc/{pid}/status"
-    with open(path) as f:
-        for line in f:
-            if line.startswith("Mems_allowed_list:"):
-                # Extract the string part (e.g., "0-1,3")
-                raw_list = line.split(":")[1].strip()
-                return parse_id_list(raw_list)
+    try:
+        with open(path) as f:
+            for line in f:
+                if line.startswith("Mems_allowed_list:"):
+                    # Extract the string part (e.g., "0-1,3")
+                    raw_list = line.split(":")[1].strip()
+                    return parse_id_list(raw_list)
+    except FileNotFoundError:
+        pass
     return []


@@ -187,8 +192,8 @@ def get_memory_node_info(node_id: int = 0) -> MemoryNo


 def get_memory_node_info(node_id: int = 0) -> MemoryNodeInfo:
-    if sys.platform == "darwin":
-        # MacOS has no memory node
+    if sys.platform.startswith(("darwin", "freebsd")):
+        # MacOS/FreeBSD has no memory node
         return MemoryNodeInfo(
             total_memory=psutil.virtual_memory().total,
             available_memory=psutil.virtual_memory().available,
@@ -256,7 +261,7 @@ def get_visible_memory_node(assigned_node_ids: list[in
     parallel_config.assigned_physical_gpu_ids. It takes priority over the
     CPU_VISIBLE_MEMORY_NODES env var, which still applies when it is None.
     """
-    if sys.platform == "darwin":
+    if sys.platform.startswith(("darwin", "freebsd")):
         return [0]

     allowed_memory_node_list = get_memory_affinity()
@@ -289,8 +294,8 @@ def _get_cpu_list() -> list[LogicalCPUInfo]:


 def _get_cpu_list() -> list[LogicalCPUInfo]:
-    if sys.platform == "darwin":
-        # For MacOS, no user-level CPU affinity and SMT, return all CPUs
+    if sys.platform.startswith(("darwin", "freebsd")):
+        # For MacOS/FreeBSD, no user-level CPU affinity and SMT, return all CPUs
         return _synthesize_cpu_list()

     if platform.machine() == "s390x":
