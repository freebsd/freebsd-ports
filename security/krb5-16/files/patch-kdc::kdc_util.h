Index: kdc/kdc_util.h
===================================================================
RCS file: /cvs/krbdev/krb5/src/kdc/kdc_util.h,v
retrieving revision 5.44.4.1
diff -u -r5.44.4.1 kdc_util.h
--- kdc/kdc_util.h	2001/10/13 00:12:26	5.44.4.1
+++ kdc/kdc_util.h	2002/10/15 23:32:45
@@ -183,6 +183,7 @@
 				      const krb5_fulladdr *,
 				      int is_secondary,
 				      krb5_data **));
+void enable_v4_crossrealm(char *);
 #else
 #define process_v4(foo,bar,quux,foobar)	KRB5KRB_AP_ERR_BADVERSION
 #endif
