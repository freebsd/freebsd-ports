--- libddr_crypt.c.orig	2022-07-26 10:06:31 UTC
+++ libddr_crypt.c
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <time.h>
-#include <endian.h>
+#include <machine/endian.h>
 #include <signal.h>
 
 #ifdef HAVE_SYS_XATTR_H
