--- deps/openssl/config/opensslconf_no-asm.h.orig	2019-05-28 21:32:16 UTC
+++ deps/openssl/config/opensslconf_no-asm.h
@@ -18,8 +18,8 @@
 # include "./archs/VC-WIN64A/no-asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_ARM64)
 # include "./archs/VC-WIN64-ARM/no-asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/no-asm/include/openssl/opensslconf.h"
+//#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+//# include "./archs/BSD-x86/no-asm/include/openssl/opensslconf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
