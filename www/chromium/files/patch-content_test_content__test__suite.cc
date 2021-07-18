--- content/test/content_test_suite.cc.orig	2021-04-14 18:41:03 UTC
+++ content/test/content_test_suite.cc
@@ -83,6 +83,7 @@ void ContentTestSuite::Initialize() {
   // to initialize GL, so don't do it here.
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   bool is_child_process = command_line->HasSwitch(switches::kTestChildProcess);
+#if !defined(OS_BSD)
   if (!is_child_process) {
     gl::GLSurfaceTestSupport::InitializeNoExtensionsOneOff();
     auto* gpu_feature_info = gpu::GetTestGpuThreadHolder()->GetGpuFeatureInfo();
@@ -90,6 +91,7 @@ void ContentTestSuite::Initialize() {
         gpu_feature_info->disabled_extensions);
     gl::init::InitializeExtensionSettingsOneOffPlatform();
   }
+#endif
   // TestEventListeners repeater event propagation is disabled in death test
   // child process.
   if (command_line->HasSwitch("gtest_internal_run_death_test")) {
