--- libraries/liblunicode/ucstr.c.orig	Fri Apr 11 03:57:10 2003
+++ libraries/liblunicode/ucstr.c	Sun Jul  6 02:50:32 2003
@@ -10,7 +10,7 @@
 #include <ac/string.h>
 #include <ac/stdlib.h>
 
-#include <lber.h>
+#include <lber_pvt.h>
 
 #include <ldap_utf8.h>
 #include <ldap_pvt_uc.h>
