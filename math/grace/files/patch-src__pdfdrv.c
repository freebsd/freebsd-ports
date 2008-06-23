--- src/pdfdrv.c.orig	2004-08-05 04:37:47.000000000 +0900
+++ src/pdfdrv.c	2008-06-16 15:29:00.000000000 +0900
@@ -57,6 +57,8 @@
 #  include "motifinc.h"
 #endif
 
+#define PDF_set_fillrule(handle, rule) PDF_set_parameter(handle, "fillrule", rule)
+
 static void pdf_error_handler(PDF *p, int type, const char* msg);
 
 static unsigned long page_scale;
