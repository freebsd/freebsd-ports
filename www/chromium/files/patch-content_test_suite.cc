--- content/test/content_test_suite.cc.orig	2017-06-22 13:36:32.924786000 +0200
+++ content/test/content_test_suite.cc	2017-06-22 13:39:16.176707000 +0200
@@ -85,6 +85,7 @@
   // to initialize GL, so don't do it here.
   bool is_child_process = base::CommandLine::ForCurrentProcess()->HasSwitch(
       switches::kTestChildProcess);
+#if !defined(OS_BSD)
   if (!is_child_process) {
     gpu::GPUInfo gpu_info;
     gpu::CollectBasicGraphicsInfo(&gpu_info);
@@ -92,6 +93,7 @@
                                       base::CommandLine::ForCurrentProcess());
     gl::GLSurfaceTestSupport::InitializeOneOff();
   }
+#endif
   testing::TestEventListeners& listeners =
       testing::UnitTest::GetInstance()->listeners();
   listeners.Append(new TestInitializationListener);
