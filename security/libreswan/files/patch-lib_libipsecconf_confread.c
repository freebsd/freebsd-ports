--- lib/libipsecconf/confread.c.orig	2021-05-21 21:27:40 UTC
+++ lib/libipsecconf/confread.c
@@ -33,6 +33,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <assert.h>
+#include <sys/socket.h>
 
 #include "lswalloc.h"
 #include "ip_address.h"
