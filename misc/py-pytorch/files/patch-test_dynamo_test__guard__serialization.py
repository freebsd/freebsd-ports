--- test/dynamo/test_guard_serialization.py.orig	2026-10-28 18:13:22 UTC
+++ test/dynamo/test_guard_serialization.py
@@ -4136,6 +4136,7 @@ class TestGuardSerialization(TestGuardSerializationBas
             True,
         )
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_ddp_module(self):
         import torch.distributed as dist
 
@@ -4190,6 +4191,7 @@ class TestGuardSerialization(TestGuardSerializationBas
             True,
         )
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unserializable_sharded_tensor(self):
         import torch.distributed as dist
 
@@ -4305,6 +4307,7 @@ class TestGuardSerialization(TestGuardSerializationBas
         )
         self._test_check_fn(ref, loaded, {"inputs": Inputs(x, torch.Stream())}, True)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unused_process_group(self):
         import torch.distributed as dist
 
