--- clients/ksu/krb_auth_su.c.orig	Mon Dec  6 13:56:09 1999
+++ clients/ksu/krb_auth_su.c	Tue Feb 25 19:54:14 2003
@@ -620,7 +620,9 @@
                   	      krb5_princ_realm(context, temp_client)->length))){
 
 
-			if(nelem){ 
+			if(nelem &&
+			   (krb5_princ_size(context, *client) > 0) &&
+			   (krb5_princ_size(context, temp_client) > 0)){
 				krb5_data *p1 =
 				 krb5_princ_component(context, *client, 0);
         			krb5_data *p2 = 
