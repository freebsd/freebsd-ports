Fix the virtual alias support.
Implement SQL_REMOVE_DELETED.

--- a/vmysql.c
+++ b/vmysql.c
@@ -596,12 +596,14 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
        "delete from vlog where domain = '%s'", domain );
     if (mysql_query(&mysql_update,SqlBufUpdate)) {
        return(-1);
     }
 #endif
+#endif
 
     vdel_limits(domain);
 
@@ -647,6 +649,7 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
         "delete from vlog where domain = '%s' and user = '%s'", 
        domain, user );
@@ -654,6 +657,7 @@
         err = -1;
     }
 #endif
+#endif
     return(err);
 }
 
@@ -1580,7 +1584,7 @@
  *  valias_select_names
  */
 
-char *valias_select_names( char *alias, char *domain )
+char *valias_select_names( char *domain )
 {
  struct linklist *temp_entry = NULL;
 
@@ -1609,16 +1613,13 @@
     }
 
     while ((row = mysql_fetch_row(res_read))) {
-        temp_entry = linklist_add (temp_entry, row[1], row[0]);
+        temp_entry = linklist_add (temp_entry, row[0], "");
         if (valias_current == NULL) valias_current = temp_entry;
     }
     mysql_free_result (res_read);
  
     if (valias_current == NULL) return NULL; /* no results */
-    else {
-        strcpy (alias, valias_current->d2);
-        return(valias_current->data);
-    }
+    else return(valias_current->data);
 }
 
 /************************************************************************
@@ -1626,16 +1627,13 @@
  *  valias_select_names_next
  */
 
-char *valias_select_names_next(char *alias)
+char *valias_select_names_next()
 {
     if (valias_current == NULL) return NULL;
     valias_current = linklist_del (valias_current);
  
     if (valias_current == NULL) return NULL; /* no results */
-    else {
-        strcpy (alias, valias_current->d2);
-        return(valias_current->data);
-    }
+    else return(valias_current->data);
 }
 
 
