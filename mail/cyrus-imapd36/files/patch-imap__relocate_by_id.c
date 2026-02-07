Index: imap/relocate_by_id.c
diff -u -p imap/relocate_by_id.c.orig imap/relocate_by_id.c
--- imap/relocate_by_id.c.orig	2022-12-12 11:04:29.000000000 +0900
+++ imap/relocate_by_id.c	2023-02-11 17:56:42.710449000 +0900
@@ -45,6 +45,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <libgen.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
