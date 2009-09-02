--- lib/hdb/hdb-ldap.c	2008-10-12 01:15:38.000000000 +0000
+++ lib/hdb/hdb-ldap.c	2008-10-12 01:15:55.000000000 +0000
@@ -222,7 +222,7 @@
 
 	(*modlist)[cMods]->mod_bvalues = bv;
 
-	bv[i] = ber_memalloc(sizeof(*bv));;
+	bv[i] = ber_memalloc(sizeof(**bv));;
 	if (bv[i] == NULL)
 	    return ENOMEM;
 
