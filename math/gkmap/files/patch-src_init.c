--- src/init.c.orig	2021-11-02 09:37:31 UTC
+++ src/init.c
@@ -1,5 +1,11 @@
 #include "kmap_struct.h" 
 	
+/* globals */
+struct cell cell_array[4][4];
+struct output out_array[20];
+char semi_final_out[70];
+char final_out[100];
+
 void init_kmap(void) 
 {
 	int i,j;
