--- imap/relocate_by_id.c.orig	2023-02-27 02:08:04 UTC
+++ imap/relocate_by_id.c
@@ -46,6 +46,7 @@
 #include <unistd.h>
 #endif
 #include <getopt.h>
+#include <libgen.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <errno.h>
