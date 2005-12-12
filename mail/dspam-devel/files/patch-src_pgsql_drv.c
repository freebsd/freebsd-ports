Index: src/pgsql_drv.c
===================================================================
RCS file: /usr/local/cvsroot/dspam/src/pgsql_drv.c,v
retrieving revision 1.47
retrieving revision 1.48
diff -u -r1.47 -r1.48
--- src/pgsql_drv.c	9 Oct 2005 20:29:55 -0000	1.47
+++ src/pgsql_drv.c	2 Dec 2005 05:06:11 -0000	1.48
@@ -1,4 +1,4 @@
-/* $Id: pgsql_drv.c,v 1.47 2005/10/09 20:29:55 jonz Exp $ */
+/* $Id: pgsql_drv.c,v 1.48 2005/12/02 05:06:11 jonz Exp $ */
 
 /*
  DSPAM
@@ -1923,7 +1923,7 @@
 
 #ifdef USE_LDAP
   if (_ds_match_attribute(CTX->config->attributes, "LDAPMode", "verify") &&
-      !ldap_verify(CTX, name))
+      ldap_verify(CTX, name)<=0)
   {
     LOGDEBUG("LDAP verification of %s failed: not adding user", name);
     return NULL;
