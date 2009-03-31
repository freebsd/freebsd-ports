--- memtest.lds	2008-11-16 02:18:14.000000000 +0200
+++ memtest.lds	2009-02-18 00:24:22.000000000 +0200
@@ -3,7 +3,7 @@
 
 ENTRY(_start); 
 SECTIONS {
-	. = 0x10000;
+	. = 0xc0120000;
 	_start = . ;
 	.data : {
 		*(.data)
