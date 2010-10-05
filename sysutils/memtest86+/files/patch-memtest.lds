
$FreeBSD$

--- memtest.lds.orig
+++ memtest.lds
@@ -3,7 +3,7 @@
 
 ENTRY(_start); 
 SECTIONS {
-	. = 0x5000;
+ 	. = 0xc0120000;
 	_start = . ;
 	.data : {
 		*(.data)
