--- client/clparse.c.orig	Mon Feb 10 01:39:57 2003
+++ client/clparse.c	Wed Mar  3 01:35:39 2004
@@ -785,7 +785,7 @@
 		if (status != ISC_R_SUCCESS)
 			log_fatal ("Can't record interface %s: %s",
 				   name, isc_result_totext (status));
-		strcpy (ip -> name, name);
+		strlcpy (ip -> name, name, IFNAMSIZ);
 		if (dummy_interfaces) {
 			interface_reference (&ip -> next,
 					     dummy_interfaces, MDL);
