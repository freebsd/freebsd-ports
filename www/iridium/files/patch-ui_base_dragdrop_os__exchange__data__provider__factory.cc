--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2019-03-11 22:01:19 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -8,7 +8,7 @@
 
 #if defined(USE_X11)
 #include "ui/base/dragdrop/os_exchange_data_provider_aurax11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_aura.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/dragdrop/os_exchange_data_provider_builder_mac.h"
@@ -42,7 +42,7 @@ OSExchangeDataProviderFactory::CreateProvider() {
 
 #if defined(USE_X11)
   return std::make_unique<OSExchangeDataProviderAuraX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<OSExchangeDataProviderAura>();
 #elif defined(OS_MACOSX)
   return ui::BuildOSExchangeDataProviderMac();
