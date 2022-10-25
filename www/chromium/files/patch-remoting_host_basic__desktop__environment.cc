--- remoting/host/basic_desktop_environment.cc.orig	2022-10-24 13:33:33 UTC
+++ remoting/host/basic_desktop_environment.cc
@@ -190,7 +190,7 @@ BasicDesktopEnvironment::CreateVideoCapturer() {
   scoped_refptr<base::SingleThreadTaskRunner> capture_task_runner;
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   capture_task_runner = ui_task_runner_;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Each capturer instance should get its own thread so the capturers don't
   // compete with each other in multistream mode.
   capture_task_runner = base::ThreadPool::CreateSingleThreadTaskRunner(
