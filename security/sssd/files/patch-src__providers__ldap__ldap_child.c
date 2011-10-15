--- ./src/providers/ldap/ldap_child.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/ldap/ldap_child.c	2011-10-13 12:15:03.000000000 -0400
@@ -165,7 +165,7 @@
         }
 
         realm_name = talloc_strdup(memctx, default_realm);
-        krb5_free_default_realm(context, default_realm);
+        free(default_realm);
         if (!realm_name) {
             krberr = KRB5KRB_ERR_GENERIC;
             goto done;
@@ -279,20 +279,20 @@
         goto done;
     }
 
-    krberr = krb5_get_time_offsets(context, &kdc_time_offset, &kdc_time_offset_usec);
-    if (krberr) {
-        DEBUG(2, ("Failed to get KDC time offset: %s\n",
-                  sss_krb5_get_error_message(context, krberr)));
-        kdc_time_offset = 0;
-    } else {
-        if (kdc_time_offset_usec > 0) {
-            kdc_time_offset++;
-        }
-    }
+    //    krberr = krb5_get_time_offsets(context, &kdc_time_offset, &kdc_time_offset_usec);
+    //    if (krberr) {
+    //        DEBUG(2, ("Failed to get KDC time offset: %s\n",
+    //                  sss_krb5_get_error_message(context, krberr)));
+    //        kdc_time_offset = 0;
+    //    } else {
+    //        if (kdc_time_offset_usec > 0) {
+    //            kdc_time_offset++;
+    //        }
+    //    }
 
     krberr = 0;
     *ccname_out = ccname;
-    *expire_time_out = my_creds.times.endtime - kdc_time_offset;
+    *expire_time_out = my_creds.times.endtime;
 
 done:
     if (keytab) krb5_kt_close(context, keytab);
