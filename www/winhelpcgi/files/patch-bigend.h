--- libhlpaccess/bigend.h.orig	Sun May 16 13:35:18 2004
+++ libhlpaccess/bigend.h	Wed Jan  5 17:00:48 2005
@@ -4,9 +4,11 @@
  *
  */
 
-#if   defined(__powerpc__) || defined(__ppc__) || defined(__sparc__) || defined(_AIX)
+#include <sys/endian.h>
+
+#if BYTE_ORDER == BIG_ENDIAN
 # define BIGENDIAN       /* This is a big-endian machine MSB is the first Byte */
-#elif defined(__i386__) || defined(__alpha__) || defined(__amd64__)
+#elif BYTE_ORDER == LITTLE_ENDIAN
 # define LITTLEENDIAN    /* This is a little-endian machine MSB is the last Byte */
 #else
 # error Endianness undefined

