--- ./database.c.orig	2004-04-13 02:46:24.000000000 +0200
+++ ./database.c	2014-08-15 19:09:39.000000000 +0200
@@ -160,6 +160,12 @@
     panda_windbwrite (document, key, value);
 #else
 
+#ifdef USE_EDB
+  e_db_data_set((E_DB_File *)document->db, key, value, strlen(value)+1);
+#else
+  DBT db_key, db_data;
+  int ec;
+
 #if defined DEBUG
   printf ("Storing (%s, %s) in 0x%08x\n", key, value, document->db);
 #endif
@@ -169,13 +175,6 @@
   if (value == NULL)
     panda_error (panda_true, "Cannot store null value\n");
 
-#ifdef USE_EDB
-
-  e_db_data_set((E_DB_File *)document->db, key, value, strlen(value)+1);
-#else
-  DBT db_key, db_data;
-  int ec;
-
   memset(&db_key, 0, sizeof(db_key));
   memset(&db_data, 0, sizeof(db_data));
   db_key.data = key;
