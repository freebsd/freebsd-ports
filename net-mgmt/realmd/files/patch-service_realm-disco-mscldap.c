--- service/realm-disco-mscldap.c.orig	2022-09-29 11:05:56 UTC
+++ service/realm-disco-mscldap.c
@@ -22,6 +22,9 @@
 #include <glib/gi18n.h>
 
 #include <errno.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #include <unistd.h>
 
