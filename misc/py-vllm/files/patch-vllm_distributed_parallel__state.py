--- vllm/distributed/parallel_state.py.orig	2026-11-02 08:07:03 UTC
+++ vllm/distributed/parallel_state.py
@@ -26,6 +26,7 @@ import pickle
 import contextlib
 import gc
 import pickle
+import sys
 import weakref
 from collections import deque, namedtuple
 from collections.abc import Callable
@@ -355,10 +356,15 @@ def _create_subgroups_split_group(
     # was bound to via ``device_id``), so a cpu-only filter is rejected.
     # Include the device backend in the filter; only the gloo backend is
     # actually used for CPU collectives on this group.
+    # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+    _cpu_backend = "gloo"
+    if sys.platform.startswith("freebsd"):
+        import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+        _cpu_backend = "fake"
     self_cpu_group = torch.distributed.split_group(
         split_ranks=group_ranks,
         group_desc=f"{group_name}:cpu",
-        backend=f"cpu:gloo,{device_backend_str}",
+        backend=f"cpu:{_cpu_backend},{device_backend_str}",
         timeout=get_cpu_distributed_timeout_or_none(),
     )
     return self_device_group, self_cpu_group
@@ -507,9 +513,14 @@ class GroupCoordinator:
                 )
                 # a group with `gloo` backend, to allow direct coordination between
                 # processes through the CPU.
+                # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+                _cpu_backend = "gloo"
+                if sys.platform.startswith("freebsd"):
+                    import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+                    _cpu_backend = "fake"
                 with suppress_stdout():
                     cpu_group = torch.distributed.new_group(
-                        ranks, backend="gloo", timeout=self.cpu_timeout
+                        ranks, backend=_cpu_backend, timeout=self.cpu_timeout
                     )
                 if self.rank in ranks:
                     self.ranks = ranks
@@ -1760,7 +1771,12 @@ def _init_process_group_for_split_group(
         )
         device_id: torch.device | None = torch.device(f"cuda:{visible_device_index}")
     else:
-        init_backend = "gloo"
+        # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+        if sys.platform.startswith("freebsd"):
+            import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+            init_backend = "fake"
+        else:
+            init_backend = "gloo"
         device_id = None
     torch.distributed.init_process_group(
         backend=init_backend,
@@ -1943,10 +1959,15 @@ def init_distributed_environment(
                 "Distributed backend %s is not available; falling back to gloo.",
                 backend,
             )
-            assert torch.distributed.is_gloo_available(), (
-                "Fallback Gloo backend is not available."
-            )
-            backend = "gloo"
+            # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+            if sys.platform.startswith("freebsd"):
+                import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+                backend = "fake"
+            else:
+                assert torch.distributed.is_gloo_available(), (
+                    "Fallback Gloo backend is not available."
+                )
+                backend = "gloo"
         store = world_pg_store
         if store is None and distributed_init_method.startswith("file://"):
             store = torch.distributed.FileStore(
@@ -1973,6 +1994,9 @@ def init_distributed_environment(
             )
         else:
             # this backend is used for WORLD
+            # On FreeBSD, register the 'fake' backend before use.
+            if sys.platform.startswith("freebsd") and backend == "fake":
+                import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
             torch.distributed.init_process_group(
                 backend=backend,
                 init_method=distributed_init_method if store is None else None,
@@ -1982,8 +2006,13 @@ def init_distributed_environment(
                 timeout=timeout,
             )
         if enable_elastic_ep:
+            # On FreeBSD, gloo TCP transport is unavailable; use fake backend.
+            _cpu_backend = "gloo"
+            if sys.platform.startswith("freebsd"):
+                import importlib; importlib.import_module("torch.testing._internal.distributed.fake_pg")
+                _cpu_backend = "fake"
             tp_pp_cpu_group = torch.distributed.new_group(
-                backend="gloo", timeout=timeout
+                backend=_cpu_backend, timeout=timeout
             )
             if _node_count(tp_pp_cpu_group) > 1:
                 # NOTE(yongji): StatelessGroupCoordinator uses data_parallel_master_ip
