--- src/kmap_struct.h.orig	2021-11-02 09:33:21 UTC
+++ src/kmap_struct.h
@@ -36,7 +36,7 @@ struct cell
 	struct cell *left,*right,*down,*up;
 	char col_string[3], row_string[3];
 };
-struct cell cell_array[4][4];
+extern struct cell cell_array[4][4];
 	
 struct output
 {
@@ -44,10 +44,10 @@ struct output
 	char cell_num_string[10];
 	int status;
 };
-struct output out_array[20];
-	
-char semi_final_out[70];
-char final_out[100];
+extern struct output out_array[20];
+
+extern char semi_final_out[70];
+extern char final_out[100];
 
 
 	
