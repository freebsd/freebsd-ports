
$FreeBSD$

--- modules/postgres/dbase.h.orig	Tue Apr  8 04:25:35 2003
+++ modules/postgres/dbase.h	Tue Apr 13 22:27:28 2004
@@ -106,4 +106,16 @@
 	      db_key_t* _uk, db_val_t* _uv, int _n, int _un);
 
 
+/*
+ * Store name of table that will be used by
+ * subsequent database functions
+ */
+int use_table(db_con_t* _h, const char* _t);
+
+int val2str(db_val_t* _v, char* _s, int* _len);
+
+int free_result(db_res_t* _r);
+
+int convert_result(db_con_t* _h, db_res_t* _r);
+
 #endif /* DBASE_H */
