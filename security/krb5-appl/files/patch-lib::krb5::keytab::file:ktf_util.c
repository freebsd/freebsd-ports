diff -ur krb5-1.2.7/src/lib/krb5/keytab/file/ktf_util.c krb5-1.2.7/src/lib/krb5/keytab/file/ktf_util.c
--- lib/krb5/keytab/file/ktf_util.c	1999-09-24 17:19:01.000000000-0400
+++ lib/krb5/keytab/file/ktf_util.c	2003-02-03 18:02:25.000000000-0500
@@ -441,7 +441,7 @@
     return 0;
 fail:
     
-    for (i = 0; i < ret_entry->principal->length; i++) {
+    for (i = 0; i < krb5_princ_size(context, ret_entry->principal); i++) {
 	    princ = krb5_princ_component(context, ret_entry->principal, i);
 	    if (princ->data)
 		    free(princ->data);
@@ -498,9 +498,9 @@
     }

     if (KTVERSION(id) == KRB5_KT_VNO_1) {
-	    count = (krb5_int16) entry->principal->length + 1;
+	    count = (krb5_int16) krb5_princ_size(context, entry->principal) + 1;
     } else {
-	    count = htons((u_short) entry->principal->length);
+	    count = htons((u_short) krb5_princ_size(context, entry->principal));
     }

     if (!xfwrite(&count, sizeof(count), 1, KTFILEP(id))) {
@@ -519,7 +519,7 @@
 	    goto abend;
     }

-    count = (krb5_int16) entry->principal->length;
+    count = (krb5_int16) krb5_princ_size(context, entry->principal);
     for (i = 0; i < count; i++) {
 	princ = krb5_princ_component(context, entry->principal, i);
 	size = princ->length;
@@ -620,7 +620,7 @@
     krb5_int32 total_size, i;
     krb5_error_code retval = 0;

-    count = (krb5_int16) entry->principal->length;
+    count = (krb5_int16) krb5_princ_size(context, entry->principal);
         
     total_size = sizeof(count);
     total_size += krb5_princ_realm(context, entry->principal)->length + (sizeof(krb5_int16));
