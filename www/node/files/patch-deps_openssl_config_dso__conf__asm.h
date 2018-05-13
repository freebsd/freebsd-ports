--- deps/openssl/config/dso_conf_asm.h.orig	2018-05-11 12:02:07 UTC
+++ deps/openssl/config/dso_conf_asm.h
@@ -21,8 +21,8 @@
 # include "./archs/VC-WIN32/asm/crypto/include/internal/dso_conf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/asm/crypto/include/internal/dso_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/asm/crypto/include/internal/dso_conf.h"
+//#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+//# include "./archs/BSD-x86/asm/crypto/include/internal/dso_conf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/crypto/include/internal/dso_conf.h"
 #elif defined(__sun) && defined(__i386__)
