--- src/quote_fmt_lex.c.orig	Sun Feb 29 17:49:24 2004
+++ src/quote_fmt_lex.c	Sun Feb 29 17:50:05 2004
@@ -21,7 +21,9 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#if __FreeBSD__ > 4
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
