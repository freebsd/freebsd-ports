--- libddr_hash.c.orig	2017-08-25 15:14:33 UTC
+++ libddr_hash.c
@@ -34,7 +34,7 @@
 #include <fcntl.h>
 
 #include <netinet/in.h>	/* For ntohl/htonl */
-#include <endian.h>
+#include <machine/endian.h>
 
 #ifdef HAVE_ATTR_XATTR_H
 #include <attr/xattr.h>
