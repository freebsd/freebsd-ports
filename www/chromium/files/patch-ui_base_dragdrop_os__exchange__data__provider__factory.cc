--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc
@@ -8,7 +8,7 @@
 
 #if defined(USE_X11) && !defined(OS_CHROMEOS)
 #include "ui/base/dragdrop/os_exchange_data_provider_aurax11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_aura.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/dragdrop/os_exchange_data_provider_builder_mac.h"
@@ -42,7 +42,7 @@ OSExchangeDataProviderFactory::CreateProvider() {
 
 #if defined(USE_X11) && !defined(OS_CHROMEOS)
   return base::MakeUnique<OSExchangeDataProviderAuraX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return base::MakeUnique<OSExchangeDataProviderAura>();
 #elif defined(OS_MACOSX)
   return ui::BuildOSExchangeDataProviderMac();
