--- smtpserver/smtpetrn.c.orig	Sun Sep 24 14:05:20 2006
+++ smtpserver/smtpetrn.c	Sun Sep 24 14:06:45 2006
@@ -21,6 +21,8 @@
 
 #ifndef HAVE_OPENSSL
 #include "md5.h"
+#else
+#include <openssl/md5.h>
 #endif /* --HAVE_OPENSSL */
 
 static int local_etrn(SS, name, cp, silence)
