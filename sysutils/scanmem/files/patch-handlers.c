--- handlers.c.orig	2017-10-13 21:53:16 UTC
+++ handlers.c
@@ -38,7 +38,9 @@
 #include <signal.h>
 #include <assert.h>
 #include <setjmp.h>
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <strings.h>
 #include <string.h>
 #include <stdbool.h>
