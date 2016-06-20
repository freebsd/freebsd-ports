--- src/tspi/ps/ps_utils.c.orig	2016-06-20 15:21:26 UTC
+++ src/tspi/ps/ps_utils.c
@@ -22,7 +22,7 @@
 #include "tspps.h"
 #include "tsplog.h"
 
-inline TSS_RESULT
+TSS_RESULT
 read_data(int fd, void *data, UINT32 size)
 {
 	int rc;
@@ -39,7 +39,7 @@ read_data(int fd, void *data, UINT32 siz
 	return TSS_SUCCESS;
 }
 
-inline TSS_RESULT
+TSS_RESULT
 write_data(int fd, void *data, UINT32 size)
 {
 	int rc;
