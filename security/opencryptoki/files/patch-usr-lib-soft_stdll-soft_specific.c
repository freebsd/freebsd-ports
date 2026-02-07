--- usr/lib/soft_stdll/soft_specific.c.orig	2022-04-25 11:04:51 UTC
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
@@ -38,7 +42,17 @@
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
 
 #include <openssl/rand.h>
 #include <openssl/dh.h>
