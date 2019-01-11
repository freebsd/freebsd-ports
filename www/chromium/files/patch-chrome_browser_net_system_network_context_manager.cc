--- chrome/browser/net/system_network_context_manager.cc.orig	2019-01-09 22:09:37.510094000 +0100
+++ chrome/browser/net/system_network_context_manager.cc	2019-01-09 22:10:30.828698000 +0100
@@ -67,7 +67,7 @@
 #include "chrome/browser/chromeos/policy/browser_policy_connector_chromeos.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/common/chrome_paths_internal.h"
 #include "chrome/common/chrome_switches.h"
 #include "chrome/grit/chromium_strings.h"
@@ -513,7 +513,7 @@
   content::GetNetworkService()->ConfigureStubHostResolver(
       stub_resolver_enabled, std::move(dns_over_https_servers));
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
 
