--- stage2/xfs.h.orig	Sat Oct 27 12:04:25 2001
+++ stage2/xfs.h	Tue Jul  9 16:03:40 2002
@@ -33,7 +33,9 @@
  *  http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/
  */
 
-#ifndef _BITS_TYPES_H
+#include <sys/types.h>
+
+#if 0
 typedef signed char	__int8_t;
 typedef unsigned char	__uint8_t;
 typedef short		__int16_t;
