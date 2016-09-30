--- memtest.lds.orig	2013-08-10 02:01:58 UTC
+++ memtest.lds
@@ -3,7 +3,7 @@ OUTPUT_ARCH(i386);
 
 ENTRY(_start); 
 SECTIONS {
-	. = 0x10000;
+	. = 0xc0120000;
 	_start = . ;
 	.data : {
 		*(.data)
