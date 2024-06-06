--- service/realm-disco-rootdse.c.orig	2022-09-29 11:05:56 UTC
+++ service/realm-disco-rootdse.c
@@ -23,6 +23,9 @@
 
 #include <glib/gi18n.h>
 
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 
 typedef struct _Closure Closure;
