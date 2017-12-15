--- src/H5FDdirect.c.orig	2017-06-15 15:47:13 UTC
+++ src/H5FDdirect.c
@@ -27,6 +27,8 @@
  * this file. */
 /* #define _XOPEN_SOURCE 600 */
 
+#define O_DIRECT	0x00010000
+
 #include "H5private.h"    /* Generic Functions      */
 #include "H5Eprivate.h"    /* Error handling        */
 #include "H5Fprivate.h"    /* File access        */
