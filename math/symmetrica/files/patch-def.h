--- def.h.orig	2007-12-06 16:30:56 UTC
+++ def.h
@@ -1,5 +1,6 @@
 /* file def.h SYMMETRICA */
 /* INT should always be 4 byte */
+/* Patch from SageMath */
 #ifndef DEF_H
 
 
@@ -3105,7 +3106,7 @@ extern INT Sn_wt();
 extern INT so_character ();
 extern INT so_dimension ();
 extern OBJECTKIND s_o_k();
-extern INT sort();
+extern INT sym_sort();
 extern INT sort_rows_tableaux_apply();
 extern INT sort_vector();
 extern OBJECTSELF s_o_s();
@@ -3271,7 +3272,7 @@ extern INT sub_default();
 extern INT sub_part_part();
 extern INT substitute_one_matrix ();
 extern INT substitute_one_monopoly ();
-extern INT sum();
+extern INT sym_sum();
 extern INT sum_integervector();
 extern INT sum_matrix();
 extern INT sum_vector();
