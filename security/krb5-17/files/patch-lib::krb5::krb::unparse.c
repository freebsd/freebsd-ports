Index: lib/krb5/krb/unparse.c
===================================================================
RCS file: /cvs/krbdev/krb5/src/lib/krb5/krb/unparse.c,v
retrieving revision 5.27.4.1
diff -p -u -r5.27.4.1 unparse.c
--- lib/krb5/krb/unparse.c	2002/08/12 22:55:01	5.27.4.1
+++ lib/krb5/krb/unparse.c	2003/03/19 00:39:02
@@ -153,7 +153,8 @@ krb5_unparse_name_ext(context, principal
 		*q++ = COMPONENT_SEP;
 	}
 
-	q--;			/* Back up last component separator */
+	if (i > 0)
+	    q--;		/* Back up last component separator */
 	*q++ = REALM_SEP;
 	
 	cp = krb5_princ_realm(context, principal)->data;
