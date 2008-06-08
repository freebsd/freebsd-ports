diff -urN -x .svn ../../branches/vendor/bsdproxy/accept_client.c ./accept_client.c
--- ../../branches/vendor/bsdproxy/accept_client.c	2008-06-08 22:30:53.000000000 +0300
+++ ./accept_client.c	2008-06-08 22:53:22.000000000 +0300
@@ -14,9 +14,6 @@
 #include <errno.h>
 #include "proxy_protos.h"
 
-extern int errno;
-
-
 void
 accept_client ( struct kevent *ke, struct mdata *md )
 {
