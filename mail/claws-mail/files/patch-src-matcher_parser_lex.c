--- src/matcher_parser_lex.c.orig	Mon Jul 28 15:43:46 2003
+++ src/matcher_parser_lex.c	Mon Jul 28 15:44:11 2003
@@ -21,7 +21,10 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <osreldate.h>
+#if __FreeBSD_version >= 500028
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
