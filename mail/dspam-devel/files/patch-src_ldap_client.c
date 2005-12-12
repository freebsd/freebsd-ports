Index: src/ldap_client.c
===================================================================
RCS file: /usr/local/cvsroot/dspam/src/ldap_client.c,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- src/ldap_client.c	24 Sep 2005 17:48:59 -0000	1.2
+++ src/ldap_client.c	2 Dec 2005 05:06:11 -0000	1.3
@@ -1,4 +1,4 @@
-/* $Id: ldap_client.c,v 1.2 2005/09/24 17:48:59 jonz Exp $ */
+/* $Id: ldap_client.c,v 1.3 2005/12/02 05:06:11 jonz Exp $ */
 
 /*
  DSPAM
@@ -80,7 +80,9 @@
     return EFAILURE;
   }
 
-  result = ldap_count_entries(ld, msg);
+  result = ldap_count_entries(ld, msg) > 0;
+  ldap_msgfree (msg);
+  ldap_unbind(ld);
   return result;
 }
 
