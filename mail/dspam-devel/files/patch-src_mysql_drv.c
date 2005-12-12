Index: src/mysql_drv.c
===================================================================
RCS file: /usr/local/cvsroot/dspam/src/mysql_drv.c,v
retrieving revision 1.57
retrieving revision 1.58
diff -u -r1.57 -r1.58
--- src/mysql_drv.c	1 Oct 2005 15:33:18 -0000	1.57
+++ src/mysql_drv.c	2 Dec 2005 05:06:11 -0000	1.58
@@ -1,4 +1,4 @@
-/* $Id: mysql_drv.c,v 1.57 2005/10/01 15:33:18 jonz Exp $ */
+/* $Id: mysql_drv.c,v 1.58 2005/12/02 05:06:11 jonz Exp $ */
 
 /*
  DSPAM
@@ -1804,7 +1804,7 @@
 
 #ifdef USE_LDAP
   if (_ds_match_attribute(CTX->config->attributes, "LDAPMode", "verify") &&
-      !ldap_verify(CTX, name)) 
+      ldap_verify(CTX, name)<=0) 
   {
     LOGDEBUG("LDAP verification of %s failed: not adding user", name);
     return NULL;
