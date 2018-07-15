--- libddr_crypt.c.orig	2017-12-03 21:58:24 UTC
+++ libddr_crypt.c
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <time.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <signal.h>
 
 #ifdef HAVE_ATTR_XATTR_H
