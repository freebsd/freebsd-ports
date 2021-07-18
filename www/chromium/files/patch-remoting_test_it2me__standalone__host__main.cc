--- remoting/test/it2me_standalone_host_main.cc.orig	2021-04-14 18:41:08 UTC
+++ remoting/test/it2me_standalone_host_main.cc
@@ -9,19 +9,19 @@
 #include "remoting/proto/event.pb.h"
 #include "remoting/test/it2me_standalone_host.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <gtk/gtk.h>
 
 #include "base/linux_util.h"
 #include "ui/events/platform/x11/x11_event_source.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 int main(int argc, const char** argv) {
   base::AtExitManager at_exit_manager;
   base::CommandLine::Init(argc, argv);
   remoting::test::It2MeStandaloneHost host;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Create an X11EventSource so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
@@ -39,7 +39,7 @@ int main(int argc, const char** argv) {
   // Need to prime the host OS version value for linux to prevent IO on the
   // network thread. base::GetLinuxDistro() caches the result.
   base::GetLinuxDistro();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   remoting::LoadResources("");
   host.StartOutputTimer();
   host.Run();
