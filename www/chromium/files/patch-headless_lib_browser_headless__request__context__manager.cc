--- headless/lib/browser/headless_request_context_manager.cc.orig	2019-01-09 12:40:33.617895000 +0100
+++ headless/lib/browser/headless_request_context_manager.cc	2019-01-09 12:41:13.269426000 +0100
@@ -35,7 +35,7 @@
 
 namespace {
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 static char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -252,7 +252,7 @@
       command_line->GetSwitchValueASCII(switches::kAuthServerWhitelist);
   network_service->ConfigureHttpAuthPrefs(std::move(auth_params));
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   if (manager->user_data_path_.empty()) {
     ::network::mojom::CryptConfigPtr config =
         ::network::mojom::CryptConfig::New();
