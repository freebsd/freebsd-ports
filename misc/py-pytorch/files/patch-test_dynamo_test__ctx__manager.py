--- test/dynamo/test_ctx_manager.py.orig	2026-05-13 17:40:38 UTC
+++ test/dynamo/test_ctx_manager.py
@@ -175,6 +175,7 @@ class CtxManagerTests(torch._dynamo.test_case.TestCase
             opt_fn(a)
         self.assertEqual(cnts.frame_count, 2)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_torch_profiler(self):
         # wrap torch.profiler.* as NullContextVariable and do nothing
         def fn(x):
@@ -195,6 +196,7 @@ class CtxManagerTests(torch._dynamo.test_case.TestCase
         self.assertTrue(same(ref, res))
         self.assertEqual(cnts.frame_count, 2)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_autograd_profiler(self):
         # wrap torch.autograd.profiler.* as NullContextVariable and do nothing
         def fn(x):
@@ -602,6 +604,7 @@ class CtxManagerTests(torch._dynamo.test_case.TestCase
             self.assertRaises(torch._dynamo.exc.Unsupported, fn, args, kwargs)
             self.assertEqual(torch.cuda.current_device(), initial_dev)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_autograd_profiler_enabled(self):
         def fn(x):
             if torch.autograd._profiler_enabled():
@@ -2245,6 +2248,7 @@ class GraphModule(torch.nn.Module):
         opt_f = torch.compile(f, backend="eager")
         opt_f(torch.randn(2, 2))
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_torch_profiler_use_after_with_block(self):
         counters.clear()
 
