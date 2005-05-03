--- libbalsa/address-book-ldap.c.orig	Tue May  3 01:46:59 2005
+++ libbalsa/address-book-ldap.c	Tue May  3 01:47:51 2005
@@ -41,6 +41,7 @@
 #include "address-book-ldap.h"
 #include "information.h"
 #include "libbalsa-conf.h"
+#include "i18n.h"
 
 static const int DEBUG_LDAP = 0;
 /* don't search when prefix has length shorter than LDAP_MIN_LEN */
