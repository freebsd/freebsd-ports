--- usr/lib/soft_stdll/soft_specific.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/soft_stdll/soft_specific.c
@@ -19,6 +19,10 @@
 
 ****************************************************************************/
 
+#ifndef	_BSD_SOURCE
+#define	_BSD_SOURCE
+#endif
+
 #include <pthread.h>
 #include <string.h>             // for memcmp() et al
 #include <stdlib.h>
@@ -36,7 +40,17 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#ifdef	_BYTE_ORDER
+#define	__BYTE_ORDER    _BYTE_ORDER
+#endif
+#ifdef	_LITTLE_ENDIAN
+#define	__LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+#else
 #include <endian.h>
+#endif
 
 #include <openssl/des.h>
 #include <openssl/rand.h>
