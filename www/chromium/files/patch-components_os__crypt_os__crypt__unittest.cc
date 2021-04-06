--- components/os_crypt/os_crypt_unittest.cc.orig	2021-03-12 23:57:22 UTC
+++ components/os_crypt/os_crypt_unittest.cc
@@ -21,7 +21,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "components/os_crypt/os_crypt_mocker_linux.h"
 #endif
 
