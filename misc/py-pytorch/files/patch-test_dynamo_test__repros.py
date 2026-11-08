--- test/dynamo/test_repros.py.orig	2026-10-28 18:13:22 UTC
+++ test/dynamo/test_repros.py
@@ -6504,6 +6504,7 @@ def forward(self, L_x_ : torch.Tensor, s77 : torch.Sym
         self.assertIn("torch._C._nn.linear", graph_code)
 
     @torch._dynamo.config.patch(record_runtime_overhead=True)
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_aot_autograd_runtime_wrapper_prologue_profiled(self):
         # Patch record_runtime_overhead on explicitly (rather than relying on the
         # default) so the prologue profiling marker is emitted deterministically.
