--- lexer.c.orig	Sat Jul 12 09:26:44 2003
+++ lexer.c	Sat Jul 12 09:27:04 2003
@@ -20,7 +20,9 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
