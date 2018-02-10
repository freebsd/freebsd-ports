--- include/compiler.h.orig	2018-02-06 02:48:39 UTC
+++ include/compiler.h
@@ -50,6 +50,9 @@ typedef unsigned long ulong;
 #endif
 #ifdef __FreeBSD__
 # include <sys/endian.h> /* htole32 and friends */
+# define __BYTE_ORDER BYTE_ORDER
+# define __LITTLE_ENDIAN LITTLE_ENDIAN
+# define __BIG_ENDIAN BIG_ENDIAN
 #elif defined(__OpenBSD__)
 # include <endian.h>
 # define __BYTE_ORDER BYTE_ORDER
