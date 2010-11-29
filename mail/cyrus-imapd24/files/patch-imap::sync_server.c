Index: imap/sync_server.c
diff -u -p imap/sync_server.c.orig imap/sync_server.c
--- imap/sync_server.c.orig	2010-11-29 22:28:06.000000000 +0900
+++ imap/sync_server.c	2010-11-30 03:36:56.729726291 +0900
@@ -47,6 +47,9 @@
 
 #include <config.h>
 
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
