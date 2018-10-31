--- deps/openssl/config/dso_conf_no-asm.h.orig	2018-05-09 01:59:18 UTC
+++ deps/openssl/config/dso_conf_no-asm.h
@@ -21,8 +21,8 @@
 # include "./archs/VC-WIN32/no-asm/crypto/include/internal/dso_conf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/no-asm/crypto/include/internal/dso_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/no-asm/crypto/include/internal/dso_conf.h"
+//#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+//# include "./archs/BSD-x86/no-asm/crypto/include/internal/dso_conf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/crypto/include/internal/dso_conf.h"
 #elif defined(__sun) && defined(__i386__)
