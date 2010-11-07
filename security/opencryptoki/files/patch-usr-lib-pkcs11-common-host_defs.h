--- usr/lib/pkcs11/common/host_defs.h.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/common/host_defs.h	2010-10-20 00:10:01.398983092 +0900
@@ -294,13 +294,24 @@
 /* (C) COPYRIGHT International Business Machines Corp. 2001,2002          */
 
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #ifndef _HOST_DEFS_H
 #define _HOST_DEFS_H
 
 #include <semaphore.h>
 #include <pthread.h>
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#include <sys/endian.h>
+#ifdef	_BYTE_ORDER
+#define	__BYTE_ORDER	_BYTE_ORDER
+#endif
+#ifdef	_LITTLE_ENDIAN
+#define	__LITTLE_ENDIAN	_LITTLE_ENDIAN
+#endif
+#else
 #include <endian.h>
+#endif
 
 #include "pkcs32.h"
 // Both of the strings below have a length of 32 chars and must be
