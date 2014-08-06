--- fmt_no.h.orig	2014-08-06 22:50:41.000000000 +0900
+++ fmt_no.h	2014-08-06 22:51:11.000000000 +0900
@@ -4,6 +4,8 @@
 #define _FMT_NO_H
 
 #include <sys/types.h>
+#include "ddr_ctrl.h"
+
 char* fmt_int_b(unsigned char pre, unsigned char post, unsigned int scale,
 	       	loff_t no, const char* bold, const char* norm, 
 		const char boldinvis, const unsigned char base,
