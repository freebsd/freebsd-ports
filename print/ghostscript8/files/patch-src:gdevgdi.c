--- src/gdevgdi.c.orig	Fri Feb  9 04:51:11 2001
+++ src/gdevgdi.c	Tue Aug 21 11:17:56 2001
@@ -24,6 +24,7 @@
 /* SAMSUNG GDI driver for Ghostscript */
 #include "gdevprn.h"
 #include "gdevpcl.h"
+#include "gsparam.h"
 
 
 /*
@@ -126,7 +127,7 @@
 private int
 gdi_open(gx_device *pdev)
 {	/* Change the margins if necessary. */
-	const float _ds *m = 0;
+	const float *m = 0;
 	bool move_origin = true;
 
 	static const float m_a4[4] = { GDI_MARGINS_A4 };
