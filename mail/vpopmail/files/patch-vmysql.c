Description: Fix the virtual alias support; implement SQL_REMOVE_DELETED.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-26

--- a/vmysql.c
+++ b/vmysql.c
@@ -599,6 +599,7 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
        "delete from vlog where domain = '%s'", domain );
     if (mysql_query(&mysql_update,SqlBufUpdate)) {
@@ -607,6 +608,7 @@
 		  fprintf(stderr, "vauth_deldomain: warning: mysql_query(%s) failed: %s\n", SqlBufUpdate, mysql_error(&mysql_update));
     }
 #endif
+#endif
 
     vdel_limits(domain);
 
@@ -656,6 +658,7 @@
 #endif
 
 #ifdef ENABLE_SQL_LOGGING
+#ifdef ENABLE_SQL_REMOVE_DELETED
     qnprintf( SqlBufUpdate, SQL_BUF_SIZE,
         "delete from vlog where domain = '%s' and user = '%s'", 
        domain, user );
@@ -667,6 +670,7 @@
 		  err = 0;
     }
 #endif
+#endif
     return(err);
 }
 
@@ -1593,7 +1597,7 @@
  *  valias_select_names
  */
 
-char *valias_select_names( char *alias, char *domain )
+char *valias_select_names( char *domain )
 {
  struct linklist *temp_entry = NULL;
 
@@ -1622,16 +1626,13 @@
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
@@ -1639,16 +1640,13 @@
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
 
 
