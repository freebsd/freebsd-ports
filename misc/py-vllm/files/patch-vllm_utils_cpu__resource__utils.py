--- vllm/utils/cpu_resource_utils.py.orig	2026-05-11 06:13:38 UTC
+++ vllm/utils/cpu_resource_utils.py
@@ -51,14 +51,19 @@ def get_memory_affinity(pid: int = 0) -> list[int]:
 
 
 def get_memory_affinity(pid: int = 0) -> list[int]:
+    if platform.system() != "Linux":
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
 
 
@@ -78,8 +83,8 @@ def get_memory_node_info(node_id: int = 0) -> MemoryNo
 
 
 def get_memory_node_info(node_id: int = 0) -> MemoryNodeInfo:
-    if platform.system() == "Darwin":
-        # MacOS has no memory node
+    if platform.system() in ("Darwin", "FreeBSD"):
+        # MacOS/FreeBSD has no memory node
         return MemoryNodeInfo(
             total_memory=psutil.virtual_memory().total,
             available_memory=psutil.virtual_memory().available,
@@ -132,7 +137,7 @@ def get_visible_memory_node() -> list[int]:
 
 
 def get_visible_memory_node() -> list[int]:
-    if platform.system() == "Darwin":
+    if platform.system() in ("Darwin", "FreeBSD"):
         return [0]
 
     allowed_memory_node_list = get_memory_affinity()
@@ -163,8 +168,8 @@ def _get_cpu_list() -> list[LogicalCPUInfo]:
 
 
 def _get_cpu_list() -> list[LogicalCPUInfo]:
-    if platform.system() == "Darwin":
-        # For MacOS, no user-level CPU affinity and SMT, return all CPUs
+    if platform.system() in ("Darwin", "FreeBSD"):
+        # For MacOS/FreeBSD, no user-level CPU affinity and SMT, return all CPUs
         return _synthesize_cpu_list()
 
     lscpu_output = subprocess.check_output(
