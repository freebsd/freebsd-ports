--- database.c.orig	Tue Apr 13 09:46:24 2004
+++ database.c	Fri Apr 16 01:13:10 2004
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
@@ -168,13 +174,6 @@
     panda_error (panda_true, "Cannot store null key\n");
   if (value == NULL)
     panda_error (panda_true, "Cannot store null value\n");
-
-#ifdef USE_EDB
-
-  e_db_data_set((E_DB_File *)document->db, key, value, strlen(value)+1);
-#else
-  DBT db_key, db_data;
-  int ec;
 
   memset(&db_key, 0, sizeof(db_key));
   memset(&db_data, 0, sizeof(db_data));
