diff -ur krb5-1.2.7/src/lib/krb5/krb/parse.c krb5-1.2.7/src/lib/krb5/krb/parse.c
--- lib/krb5/krb/parse.c	2002-02-28 12:08:35.000000000 -0500
+++ lib/krb5/krb/parse.c	2003-02-03 17:44:04.000000000 -0500
@@ -173,11 +173,13 @@
 				cp++;
 				size++;
 			} else if (c == COMPONENT_SEP) {
-				krb5_princ_component(context, principal, i)->length = size;
+				if (krb5_princ_size(context, principal) > i)
+					krb5_princ_component(context, principal, i)->length = size;
 				size = 0;
 				i++;
 			} else if (c == REALM_SEP) {
-				krb5_princ_component(context, principal, i)->length = size;
+				if (krb5_princ_size(context, principal) > i)
+					krb5_princ_component(context, principal, i)->length = size;
 				size = 0;
 				parsed_realm = cp+1;
 			} else
@@ -186,7 +188,8 @@
 		if (parsed_realm)
 			krb5_princ_realm(context, principal)->length = size;
 		else
-			krb5_princ_component(context, principal, i)->length = size;
+			if (krb5_princ_size(context, principal) > i)
+				krb5_princ_component(context, principal, i)->length = size;
 		if (i + 1 != components) {
 #if !defined(_MSDOS) && !defined(_WIN32) && !defined(macintosh)
 			fprintf(stderr,
