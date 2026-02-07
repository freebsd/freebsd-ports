--- database.h.orig	2015-10-04 02:38:25 UTC
+++ database.h
@@ -61,7 +61,7 @@ struct db_enumerator {
 /*
  * Field operations
  */
-inline int field_id(int i);
+int field_id(int i);
 abook_field *find_standard_field(char *key, int do_declare);
 abook_field *real_find_field(char *key, abook_field_list *list, int *nb);
 #define find_field(key, list)		real_find_field(key, list, NULL)
