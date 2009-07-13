--- ./libssh/keyfiles.c.orig	2009-05-21 18:46:17.000000000 +1000
+++ ./libssh/keyfiles.c	2009-07-09 08:21:13.000000000 +1000
@@ -29,6 +29,11 @@
 #include <stdlib.h>
 #include <fcntl.h>
 #include <ctype.h>
+
+#ifndef _WIN32
+#include <arpa/inet.h>
+#endif
+
 #include "libssh/priv.h"
 
 #ifdef HAVE_LIBGCRYPT
