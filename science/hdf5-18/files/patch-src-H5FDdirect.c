--- ./src/H5FDdirect.c.orig	2011-11-07 14:11:30.000000000 -0800
+++ ./src/H5FDdirect.c	2011-12-21 16:50:03.000000000 -0800
@@ -29,6 +29,8 @@
  * this file. */
 /* #define _XOPEN_SOURCE 600 */
 
+#define O_DIRECT	0x00010000
+
 #include "H5private.h"    /* Generic Functions      */
 #include "H5Eprivate.h"    /* Error handling        */
 #include "H5Fprivate.h"    /* File access        */
