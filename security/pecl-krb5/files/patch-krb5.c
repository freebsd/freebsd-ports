--- krb5.c.orig	2016-11-12 14:17:44 UTC
+++ krb5.c
@@ -39,6 +39,7 @@
 
 #include <sys/time.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 #ifdef HAVE_KADM5
 #include "kdb.h"
