--- ldap-pwd.c.orig	Fri Feb 24 11:02:50 2006
+++ ldap-pwd.c	Thu May 11 14:52:42 2006
@@ -21,7 +21,10 @@
 static char rcsId[] =
   "$Id: ldap-pwd.c,v 2.46 2006/01/11 18:03:49 lukeh Exp $";
 
+#include <sys/types.h>
+#include <unistd.h>
 #include "config.h"
+ 
 
 #ifdef HAVE_PORT_BEFORE_H
 #include <port_before.h>
@@ -90,9 +93,13 @@
   size_t tmplen;
   char *tmp;
 
-  if (_nss_ldap_oc_check (e, "shadowAccount") == NSS_SUCCESS)
-    {
+/*  if (_nss_ldap_oc_check (e, "shadowAccount") == NSS_SUCCESS)
+ *   {
+ */
       /* don't include password for shadowAccount */
+  if (getuid() != 0) 
+  {
+	  /* don't include password for non-root users */
       if (buflen < 3)
 	return NSS_TRYAGAIN;
 
