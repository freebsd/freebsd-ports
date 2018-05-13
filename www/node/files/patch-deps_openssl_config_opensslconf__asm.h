--- deps/openssl/config/opensslconf_asm.h.orig	2018-05-11 11:27:00 UTC
+++ deps/openssl/config/opensslconf_asm.h
@@ -108,8 +108,8 @@
 # include "./archs/VC-WIN32/asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/asm/include/openssl/opensslconf.h"
+//#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+//# include "./archs/BSD-x86/asm/include/openssl/opensslconf.h"
 #elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
