--- headless/lib/browser/headless_request_context_manager.cc.orig	2021-04-14 18:41:04 UTC
+++ headless/lib/browser/headless_request_context_manager.cc
@@ -35,7 +35,7 @@ namespace {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -73,7 +73,7 @@ void SetCryptConfigOnce(const base::FilePath& user_dat
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   ::network::mojom::CryptConfigPtr config =
       ::network::mojom::CryptConfig::New();
   config->store = base::CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
