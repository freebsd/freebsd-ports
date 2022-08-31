--- services/network/network_service.cc.orig	2022-08-31 12:19:35 UTC
+++ services/network/network_service.cc
@@ -82,7 +82,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+#if ((BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #include "components/os_crypt/key_storage_config_linux.h"
