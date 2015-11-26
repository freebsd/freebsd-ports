--- src/kerberosgss.c.orig	2015-03-29 03:40:20 UTC
+++ src/kerberosgss.c
@@ -38,7 +38,7 @@ char* server_principal_details(const cha
     int code;
     krb5_context kcontext;
     krb5_keytab kt = NULL;
-    krb5_kt_cursor cursor = NULL;
+    krb5_kt_cursor cursor;
     krb5_keytab_entry entry;
     char* pname = NULL;
     
@@ -81,13 +81,13 @@ char* server_principal_details(const cha
         {
             result = malloc(strlen(pname) + 1);
             strcpy(result, pname);
-            krb5_free_unparsed_name(kcontext, pname);
-            krb5_free_keytab_entry_contents(kcontext, &entry);
+            krb5_xfree(pname);
+            krb5_kt_free_entry(kcontext, &entry);
             break;
         }
         
-        krb5_free_unparsed_name(kcontext, pname);
-        krb5_free_keytab_entry_contents(kcontext, &entry);
+        krb5_xfree(pname);
+        krb5_kt_free_entry(kcontext, &entry);
     }
     
     if (result == NULL)
@@ -97,8 +97,7 @@ char* server_principal_details(const cha
     }
     
 end:
-    if (cursor)
-        krb5_kt_end_seq_get(kcontext, kt, &cursor);
+    krb5_kt_end_seq_get(kcontext, kt, &cursor);
     if (kt)
         krb5_kt_close(kcontext, kt);
     krb5_free_context(kcontext);
