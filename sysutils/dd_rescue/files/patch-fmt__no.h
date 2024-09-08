--- fmt_no.h.orig	2024-08-25 09:59:11 UTC
+++ fmt_no.h
@@ -8,6 +8,7 @@
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
+#include "ddr_ctrl.h"
 
 char* fmt_int_b(unsigned char pre, unsigned char post, unsigned int scale,
 		loff_t no, const char* bold, const int blen,
