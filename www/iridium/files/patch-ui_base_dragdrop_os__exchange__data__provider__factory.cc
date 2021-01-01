--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2019-07-24 18:59:18 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -8,7 +8,7 @@
 
 #if defined(USE_X11)
 #include "ui/base/dragdrop/os_exchange_data_provider_aurax11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_aura.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/dragdrop/os_exchange_data_provider_builder_mac.h"
@@ -23,7 +23,7 @@ std::unique_ptr<OSExchangeData::Provider>
 OSExchangeDataProviderFactory::CreateProvider() {
 #if defined(USE_X11)
   return std::make_unique<OSExchangeDataProviderAuraX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<OSExchangeDataProviderAura>();
 #elif defined(OS_MACOSX)
   return ui::BuildOSExchangeDataProviderMac();
