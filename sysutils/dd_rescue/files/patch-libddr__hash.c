--- libddr_hash.c.orig	2024-08-22 17:41:01 UTC
+++ libddr_hash.c
@@ -34,7 +34,7 @@
 #include <fcntl.h>
 
 #include <netinet/in.h>	/* For ntohl/htonl */
-#include <endian.h>
+#include <machine/endian.h>
 
 #ifdef HAVE_SYS_XATTR_H
 #include <sys/xattr.h>
