--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2020-07-07 21:58:19 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -9,7 +9,7 @@
 
 #if defined(USE_X11)
 #include "ui/base/dragdrop/os_exchange_data_provider_x11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #if defined(USE_OZONE)
 #include "ui/base/dragdrop/os_exchange_data_provider_factory_ozone.h"
 #endif
@@ -27,7 +27,7 @@ std::unique_ptr<OSExchangeDataProvider>
 OSExchangeDataProviderFactory::CreateProvider() {
 #if defined(USE_X11)
   return std::make_unique<OSExchangeDataProviderX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #if defined(USE_OZONE)
   // The instance can be nullptr in tests that do not instantiate the platform,
   // or on platforms that do not implement specific drag'n'drop.  For them,
