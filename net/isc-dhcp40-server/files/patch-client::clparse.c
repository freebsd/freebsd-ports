--- client/clparse.c.orig	Sat May  6 17:42:49 2006
+++ client/clparse.c	Sat May  6 17:43:12 2006
@@ -777,7 +777,7 @@
 			interface_dereference(&ip, MDL);
 			return 0;
 		}
-		strcpy(ip->name, name);
+		strlcpy (ip -> name, name, IFNAMSIZ);
 
 		if (dummy_interfaces) {
 			interface_reference (&ip -> next,
