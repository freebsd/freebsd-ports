--- usr/lib/pkcs11/soft_stdll/soft_specific.c.orig	2016-04-29 17:26:46 UTC
+++ usr/lib/pkcs11/soft_stdll/soft_specific.c
@@ -298,7 +298,9 @@
  
  
 ****************************************************************************/
+#ifndef _BSD_SOURCE
 #define _BSD_SOURCE
+#endif
 
 #include <pthread.h>
 #include <string.h>            // for memcmp() et al
@@ -317,7 +319,17 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#ifdef _BYTE_ORDER
+#define        __BYTE_ORDER    _BYTE_ORDER
+#endif
+#ifdef _LITTLE_ENDIAN
+#define        __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+#else
 #include <endian.h>
+#endif
 
 #include <openssl/des.h>
 #include <openssl/rand.h>
