--- src/3rdparty/chromium/services/network/network_service.cc.orig	2023-10-03 19:49:54 UTC
+++ src/3rdparty/chromium/services/network/network_service.cc
@@ -92,7 +92,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+#if ((BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #include "components/os_crypt/key_storage_config_linux.h"
