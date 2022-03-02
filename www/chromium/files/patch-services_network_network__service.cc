--- services/network/network_service.cc.orig	2022-02-28 16:54:41 UTC
+++ services/network/network_service.cc
@@ -77,7 +77,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
 #include "components/os_crypt/key_storage_config_linux.h"
 #endif
