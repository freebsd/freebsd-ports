--- libbalsa/address-book-ldap.c	Mon Nov 19 03:41:21 2001
+++ libbalsa/address-book-ldap.c.new	Sun Dec 16 12:59:34 2001
@@ -31,7 +31,7 @@
 #include <sys/time.h>
 #include <lber.h>
 #include <ldap.h>
-#include <iconv.h>
+#include <giconv.h>
 
 #include "address-book.h"
 #include "address-book-ldap.h"
