--- src/H5FDdirect.c.orig	2008-09-24 22:02:07.000000000 +0800
+++ src/H5FDdirect.c	2008-09-24 22:02:38.000000000 +0800
@@ -29,6 +29,8 @@
  * this file. */
 /* #define _XOPEN_SOURCE 600 */
 
+#define O_DIRECT        0x00010000
+
 #include "H5private.h"		/* Generic Functions			*/
 #include "H5Eprivate.h"		/* Error handling		  	*/
 #include "H5Fprivate.h"		/* File access				*/
