diff -urN -x .svn ../../branches/vendor/bsdproxy/read_data.c ./read_data.c
--- ../../branches/vendor/bsdproxy/read_data.c	2008-06-08 22:30:53.000000000 +0300
+++ ./read_data.c	2008-06-08 23:01:22.000000000 +0300
@@ -12,9 +12,6 @@
 #include <sys/socket.h>
 #include "proxy_protos.h"
 
-extern int errno;
-
-
 void
 read_data ( struct kevent *ke, struct mdata *md )
 {
@@ -27,7 +24,7 @@
   struct kevent      sk;
   struct sockaddr_in sa;
   socklen_t          sl;
-  char              *fr[2] = { "CLIENT", "SERVER" };
+  const char        *fr[2] = { "CLIENT", "SERVER" };
 
   /* 
      if this is the first data we're reading over this connection,
@@ -54,7 +51,7 @@
      if it fails with errno = ENOTCONN, we're not connected yet.
   */
 
-  fd = (from == CLIENT) ? r : ke->ident;
+  fd = (from == CLIENT) ? r : (int)ke->ident;
 
   if ( md->r[ke->ident].bytes_read == 0 &&
        md->r[fd].status == FD_CLOSE ) {
