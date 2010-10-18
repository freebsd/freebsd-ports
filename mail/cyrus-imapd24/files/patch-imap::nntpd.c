Index: imap/nntpd.c
diff -u -p imap/nntpd.c.orig imap/nntpd.c
--- imap/nntpd.c.orig	2010-10-12 06:35:47.000000000 +0900
+++ imap/nntpd.c	2010-10-12 12:18:23.780338789 +0900
@@ -55,6 +55,9 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
 #include <stdio.h>
 #include <errno.h>
 #include <string.h>
