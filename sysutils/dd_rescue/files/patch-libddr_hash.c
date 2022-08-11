--- libddr_hash.c.orig	2021-04-14 08:23:02 UTC
+++ libddr_hash.c
@@ -35,7 +35,7 @@
 #include <fcntl.h>
 
 #include <netinet/in.h>	/* For ntohl/htonl */
-#include <endian.h>
+#include <machine/endian.h>
 
 #ifdef HAVE_SYS_XATTR_H
 #include <sys/xattr.h>
