Index: lib/kdb/keytab.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/lib/kdb/keytab.c,v
retrieving revision 5.11.4.2
diff -u -r5.11.4.2 keytab.c
--- lib/kdb/keytab.c	2002/08/15 21:27:34	5.11.4.2
+++ lib/kdb/keytab.c	2002/10/15 23:32:46
@@ -28,6 +28,8 @@
 #include "k5-int.h"
 #include "kdb_kt.h"
 
+static int
+is_xrealm_tgt(krb5_context, krb5_const_principal);
 krb5_error_code krb5_ktkdb_close KRB5_PROTOTYPE((krb5_context, krb5_keytab));
 
 krb5_error_code krb5_ktkdb_get_entry KRB5_PROTOTYPE((krb5_context, krb5_keytab, krb5_const_principal,
@@ -98,6 +100,8 @@
     krb5_db_entry 	  db_entry;
     krb5_boolean 	  more = 0;
     int 	 	  n = 0;
+    int xrealm_tgt = is_xrealm_tgt(context, principal);
+    int similar;
 
     /* Open database */
     /* krb5_db_init(context); */
@@ -127,16 +131,31 @@
     if (kerror)
 	goto error;
 
+    /* For cross realm tgts, we match whatever enctype is provided;
+     * for other principals, we only match the first enctype that is
+     * found.  Since the TGS and AS code do the same thing, then we
+     * will only successfully decrypt  tickets we have issued.*/
     kerror = krb5_dbe_find_enctype(context, &db_entry,
-				   enctype, -1, kvno, &key_data);
+				   xrealm_tgt?enctype:-1,
+				   -1, kvno, &key_data);
     if (kerror)
 	goto error;
 
+
     kerror = krb5_dbekd_decrypt_key_data(context, master_key,
 					 key_data, &entry->key, NULL);
     if (kerror)
 	goto error;
 
+    kerror = krb5_c_enctype_compare(context, enctype, entry->key.enctype, &similar);
+    if (kerror)
+	goto error;
+
+    if (!similar) {
+		kerror = KRB5_KDB_NO_PERMITTED_KEY;
+	goto error;
+    }
+
     /*
      * Coerce the enctype of the output keyblock in case we got an
      * inexact match on the enctype; this behavior will go away when
@@ -154,3 +173,27 @@
     krb5_db_close_database(context);
     return(kerror);
 }
+
+/*
+ * is_xrealm_tgt: Returns true if the principal is a cross-realm  TGT
+ * principal-- a principal with first component  krbtgt and second
+ * component not equal to realm.
+ */
+static int
+is_xrealm_tgt(krb5_context context, krb5_const_principal princ)
+{
+    krb5_data *dat;
+    if (krb5_princ_size(context, princ) != 2)
+	return 0;
+    dat = krb5_princ_component(context, princ, 0);
+    if (strncmp("krbtgt", dat->data, dat->length) != 0)
+	return 0;
+    dat = krb5_princ_component(context, princ, 1);
+    if (dat->length != princ->realm.length)
+	return 1;
+    if (strcmp(dat->data, princ->realm.data) == 0)
+	return 0;
+    return 1;
+
+}
+
