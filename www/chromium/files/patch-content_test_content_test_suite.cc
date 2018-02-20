--- content/test/content_test_suite.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/test/content_test_suite.cc	2017-12-24 15:49:56.061177000 +0100
@@ -87,6 +87,7 @@
   // to initialize GL, so don't do it here.
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   bool is_child_process = command_line->HasSwitch(switches::kTestChildProcess);
+#if !defined(OS_BSD)
   if (!is_child_process) {
     gpu::GPUInfo gpu_info;
     gpu::CollectBasicGraphicsInfo(&gpu_info);
@@ -99,6 +100,7 @@
         gpu_feature_info.disabled_extensions);
     gl::init::InitializeExtensionSettingsOneOffPlatform();
   }
+#endif
   testing::TestEventListeners& listeners =
       testing::UnitTest::GetInstance()->listeners();
   listeners.Append(new TestInitializationListener);
