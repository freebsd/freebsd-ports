--- src/handlers.c.orig	Mon Feb 23 01:42:46 2004
+++ src/handlers.c	Wed Jun 16 20:13:06 2004
@@ -7,6 +7,10 @@
 #include "node.h"
 #include "opts.h"
 #include "wl.h"
+#if defined(__FreeBSD__)
+#include "libgen.h"
+#endif
+
 extern struct arguments_t arguments;
 struct handler_t handlers[FC_HANDLER_MAX]=
 {
