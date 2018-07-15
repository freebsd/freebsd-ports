--- fmt_no.h.orig	2017-11-09 13:09:58 UTC
+++ fmt_no.h
@@ -4,6 +4,8 @@
 #define _FMT_NO_H
 
 #include <sys/types.h>
+#include "ddr_ctrl.h"
+
 char* fmt_int_b(unsigned char pre, unsigned char post, unsigned int scale,
 		loff_t no, const char* bold, const int blen,
 		const char* norm, const int nlen,
