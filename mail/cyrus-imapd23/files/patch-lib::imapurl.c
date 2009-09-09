Index: lib/imapurl.c
diff -u -p lib/imapurl.c.orig lib/imapurl.c
--- lib/imapurl.c.orig	2009-03-31 13:11:22.000000000 +0900
+++ lib/imapurl.c	2009-09-10 00:28:05.287769072 +0900
@@ -50,6 +50,7 @@
 #include <errno.h>
 #include <limits.h>
 #include <time.h>
+#include <sys/types.h>
 
 #include "imapurl.h"
 #include "xmalloc.h"
