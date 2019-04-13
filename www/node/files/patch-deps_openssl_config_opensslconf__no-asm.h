--- deps/openssl/config/opensslconf_no-asm.h.orig	2019-04-11 12:07:35 UTC
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
