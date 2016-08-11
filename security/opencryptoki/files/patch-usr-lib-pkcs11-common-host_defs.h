--- usr/lib/pkcs11/common/host_defs.h.orig	2016-04-29 17:26:45 UTC
+++ usr/lib/pkcs11/common/host_defs.h
@@ -294,12 +294,23 @@
 /* (C) COPYRIGHT International Business Machines Corp. 2001,2002          */
 
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #ifndef _HOST_DEFS_H
 #define _HOST_DEFS_H
 
 #include <pthread.h>
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
 
 #include "pkcs32.h"
 
