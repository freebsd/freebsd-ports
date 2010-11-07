--- src/tspi/ps/ps_utils.c.orig	2010-01-29 01:27:51.000000000 +0900
+++ src/tspi/ps/ps_utils.c	2010-10-24 21:04:04.841558702 +0900
@@ -22,7 +22,7 @@
 #include "tspps.h"
 #include "tsplog.h"
 
-inline TSS_RESULT
+TSS_RESULT
 read_data(int fd, void *data, UINT32 size)
 {
 	int rc;
@@ -39,7 +39,7 @@
 	return TSS_SUCCESS;
 }
 
-inline TSS_RESULT
+TSS_RESULT
 write_data(int fd, void *data, UINT32 size)
 {
 	int rc;
