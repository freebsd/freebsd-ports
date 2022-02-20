--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -7,7 +7,7 @@
 #include "base/notreached.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_factory_ozone.h"
 #include "ui/base/dragdrop/os_exchange_data_provider_non_backed.h"
 #elif defined(OS_APPLE)
@@ -21,7 +21,7 @@ namespace ui {
 // static
 std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // The instance can be nullptr in tests that do not instantiate the platform,
   // or on platforms that do not implement specific drag'n'drop.  For them,
   // falling back to the Aura provider should be fine.
