--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -7,7 +7,7 @@
 #include "base/notreached.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_non_backed.h"
 #include "ui/base/ui_base_features.h"
 #if defined(USE_OZONE)
@@ -26,7 +26,7 @@ namespace ui {
 
 namespace {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 std::unique_ptr<OSExchangeDataProvider> CreateProviderForLinux() {
 #if defined(USE_OZONE)
   // The instance can be nullptr in tests that do not instantiate the platform,
@@ -50,7 +50,7 @@ std::unique_ptr<OSExchangeDataProvider> CreateProvider
 // static
 std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (features::IsUsingOzonePlatform())
     return CreateProviderForLinux();
 #if defined(USE_X11)
