--- ui/base/dragdrop/os_exchange_data_provider_factory.cc.orig	2018-02-24 16:25:37.000000000 +0100
+++ ui/base/dragdrop/os_exchange_data_provider_factory.cc	2018-03-04 04:46:54.356687000 +0100
@@ -9,7 +9,7 @@
 
 #if defined(USE_X11)
 #include "ui/base/dragdrop/os_exchange_data_provider_aurax11.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/dragdrop/os_exchange_data_provider_aura.h"
 #elif defined(OS_MACOSX)
 #include "ui/base/dragdrop/os_exchange_data_provider_builder_mac.h"
@@ -43,7 +43,7 @@
 
 #if defined(USE_X11)
   return std::make_unique<OSExchangeDataProviderAuraX11>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<OSExchangeDataProviderAura>();
 #elif defined(OS_MACOSX)
   return ui::BuildOSExchangeDataProviderMac();
