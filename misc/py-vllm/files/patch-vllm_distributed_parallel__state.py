--- vllm/distributed/parallel_state.py.orig	2026-04-07 18:19:15 UTC
+++ vllm/distributed/parallel_state.py
@@ -24,6 +24,7 @@ import contextlib
 """
 
 import contextlib
+import sys
 import gc
 import pickle
 import weakref
@@ -341,8 +342,13 @@ class GroupCoordinator:
             )
             # a group with `gloo` backend, to allow direct coordination between
             # processes through the CPU.
+            # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+            _cpu_backend = "gloo"
+            if sys.platform.startswith("freebsd"):
+                import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+                _cpu_backend = "fake"
             with suppress_stdout():
-                cpu_group = torch.distributed.new_group(ranks, backend="gloo")
+                cpu_group = torch.distributed.new_group(ranks, backend=_cpu_backend)
             if self.rank in ranks:
                 self.ranks = ranks
                 self.world_size = len(ranks)
@@ -1419,6 +1425,9 @@ def init_distributed_environment(
             )
             backend = "gloo"
         # this backend is used for WORLD
+        # On FreeBSD, register the 'fake' backend before use.
+        if sys.platform.startswith("freebsd") and backend == "fake":
+            import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
         torch.distributed.init_process_group(
             backend=backend,
             init_method=distributed_init_method,
