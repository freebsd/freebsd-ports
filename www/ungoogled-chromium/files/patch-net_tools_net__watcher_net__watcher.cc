--- net/tools/net_watcher/net_watcher.cc.orig	2026-01-16 13:40:34 UTC
+++ net/tools/net_watcher/net_watcher.cc
@@ -32,7 +32,7 @@
 #include "net/proxy_resolution/proxy_config_service.h"
 #include "net/proxy_resolution/proxy_config_with_annotation.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_linux.h"
 #endif
 
@@ -42,7 +42,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Flag to specifies which network interfaces to ignore. Interfaces should
 // follow as a comma seperated list.
 const char kIgnoreNetifFlag[] = "ignore-netif";
@@ -160,7 +160,7 @@ class NetWatcher :
 }  // namespace
 
 int main(int argc, char* argv[]) {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::apple::ScopedNSAutoreleasePool pool;
 #endif
   base::AtExitManager exit_manager;
@@ -177,7 +177,7 @@ int main(int argc, char* argv[]) {
 
   NetWatcher net_watcher;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   std::string ignored_netifs_str =
       command_line->GetSwitchValueASCII(kIgnoreNetifFlag);
