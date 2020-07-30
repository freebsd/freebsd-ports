--- remoting/test/it2me_standalone_host_main.cc.orig	2020-07-13 09:56:53 UTC
+++ remoting/test/it2me_standalone_host_main.cc
@@ -9,19 +9,19 @@
 #include "remoting/proto/event.pb.h"
 #include "remoting/test/it2me_standalone_host.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/gfx/x/x11.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 int main(int argc, const char** argv) {
   base::AtExitManager at_exit_manager;
   base::CommandLine::Init(argc, argv);
   remoting::test::It2MeStandaloneHost host;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
@@ -34,10 +34,12 @@ int main(int argc, const char** argv) {
   gtk_init(nullptr, nullptr);
 #endif
 
+#if !defined(OS_BSD)
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // OS_LINUX
+#endif
+#endif  // OS_LINUX || OS_BSD)
   remoting::LoadResources("");
   host.StartOutputTimer();
   host.Run();
