--- kctype.h.orig	Wed Jun 25 00:00:00 2003
+++ kctype.h	Mon Jun 30 14:55:53 2003
@@ -5,6 +5,11 @@
  */
 
 #include <ctype.h>
+#ifndef __SYS_TYPES_STAT_H_
+#define __SYS_TYPES_STAT_H_
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
 
 #define	QUOTE		('^' - '@')
 #define	C_BS		'\010'
