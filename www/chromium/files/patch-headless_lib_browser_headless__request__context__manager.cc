--- headless/lib/browser/headless_request_context_manager.cc.orig	2019-01-30 02:18:02.000000000 +0100
+++ headless/lib/browser/headless_request_context_manager.cc	2019-02-01 10:01:59.179234000 +0100
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 static char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -367,7 +367,7 @@
     return;
   if (user_data_path_.empty())
     return;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   ::network::mojom::CryptConfigPtr config =
       ::network::mojom::CryptConfig::New();
   config->store = base::CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
