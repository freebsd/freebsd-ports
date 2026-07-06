--- conversion/minctoecat/ecat_write.c.orig	2023-04-11 00:36:34 UTC
+++ conversion/minctoecat/ecat_write.c
@@ -11,6 +11,9 @@
 #define ERROR   -1
 #define V7 70
 
+MatrixErrorCode matrix_errno;
+
+char matrix_errtxt[132];
 
 char* dstypecode[NumDataSetTypes] =
 	{ "u","s","i","a","n","pm","v8","v","p8","p","i8","S","S8","N", "FS"};
