--- src/util.c.orig	Mon Nov  3 23:28:24 2003
+++ src/util.c	Thu Oct 14 12:46:42 2004
@@ -1909,7 +1909,7 @@
 char **gq_ldap_explode_dn(const char *dn, int dummy)
 {
      int i, rc;
-     LDAPDN *parts;
+     LDAPDN parts;
      char **v = 0; 
      
      rc = ldap_str2dn(dn, &parts, LDAP_DN_FORMAT_LDAPV3);
@@ -1921,7 +1921,7 @@
      v = (char **) calloc((i + 2), sizeof(char*));
 
      for( i = 0 ; parts[i] ; i++ ) {
-	  ldap_rdn2str(parts[0][i], &v[i],
+	  ldap_rdn2str(parts[i], &v[i],
 		       LDAP_DN_FORMAT_LDAPV3 | LDAP_DN_PRETTY );
      } 
      return v;
