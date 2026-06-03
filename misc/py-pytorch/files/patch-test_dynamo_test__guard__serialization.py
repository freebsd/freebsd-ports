--- test/dynamo/test_guard_serialization.py.orig	2026-05-13 17:40:38 UTC
+++ test/dynamo/test_guard_serialization.py
@@ -1521,6 +1521,7 @@ class TestGuardSerialization(TestGuardSerializationBas
         )
 
     @torch._dynamo.config.patch(nested_graph_breaks=False)
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_ddp_module(self):
         import torch.distributed as dist
 
@@ -1573,6 +1574,7 @@ class TestGuardSerialization(TestGuardSerializationBas
             True,
         )
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unserializable_sharded_tensor(self):
         import torch.distributed as dist
 
@@ -1688,6 +1690,7 @@ class TestGuardSerialization(TestGuardSerializationBas
         )
         self._test_check_fn(ref, loaded, {"inputs": Inputs(x, torch.Stream())}, True)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unused_process_group(self):
         import torch.distributed as dist
 
