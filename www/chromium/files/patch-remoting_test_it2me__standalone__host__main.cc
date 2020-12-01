--- remoting/test/it2me_standalone_host_main.cc.orig	2020-11-13 06:36:46 UTC
+++ remoting/test/it2me_standalone_host_main.cc
@@ -9,20 +9,20 @@
 #include "remoting/proto/event.pb.h"
 #include "remoting/test/it2me_standalone_host.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/events/platform/x11/x11_event_source.h"
 #include "ui/gfx/x/x11.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 int main(int argc, const char** argv) {
   base::AtExitManager at_exit_manager;
   base::CommandLine::Init(argc, argv);
   remoting::test::It2MeStandaloneHost host;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Required in order for us to run multiple X11 threads.
   XInitThreads();
 
@@ -43,7 +43,7 @@ int main(int argc, const char** argv) {
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   remoting::LoadResources("");
   host.StartOutputTimer();
   host.Run();
