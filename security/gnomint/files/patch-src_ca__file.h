--- src/ca_file.h.orig	2010-05-31 21:01:37 UTC
+++ src/ca_file.h
@@ -75,8 +75,7 @@ enum {CA_FILE_CA_COLUMN_ID=0,
       CA_FILE_CA_COLUMN_DN=3,
       CA_FILE_CA_COLUMN_PARENT_DN=4,
       CA_FILE_CA_COLUMN_PEM=5,
-      CA_FILE_CA_COLUMN_NUMBER=6}
-        CaFileCAColumns;
+      CA_FILE_CA_COLUMN_NUMBER=6};
 
 enum {CA_FILE_CERT_COLUMN_ID=0,
       CA_FILE_CERT_COLUMN_IS_CA=1,
@@ -90,16 +89,14 @@ enum {CA_FILE_CERT_COLUMN_ID=0,
       CA_FILE_CERT_COLUMN_DN=9,
       CA_FILE_CERT_COLUMN_PARENT_DN=10,
       CA_FILE_CERT_COLUMN_PARENT_ROUTE=11,
-      CA_FILE_CERT_COLUMN_NUMBER=12}
-        CaFileCertColumns;
+      CA_FILE_CERT_COLUMN_NUMBER=12};
 
 enum {CA_FILE_CSR_COLUMN_ID=0,
       CA_FILE_CSR_COLUMN_SUBJECT=1,
       CA_FILE_CSR_COLUMN_PRIVATE_KEY_IN_DB=2,
       CA_FILE_CSR_COLUMN_PEM=3,
       CA_FILE_CSR_COLUMN_PARENT_ID=4,
-      CA_FILE_CSR_COLUMN_NUMBER=5}
-        CaFileCSRColumns;
+      CA_FILE_CSR_COLUMN_NUMBER=5};
 
 
 gboolean ca_file_foreach_ca (CaFileCallbackFunc func, gpointer userdata);
