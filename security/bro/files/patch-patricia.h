--- patricia.h.orig	Sun Oct  5 18:29:52 2003
+++ patricia.h	Sun Oct  5 18:30:05 2003
@@ -51,6 +51,8 @@
 #ifndef _PATRICIA_H
 #define _PATRICIA_H
 
+#include <sys/types.h>
+
 /* typedef unsigned int u_int; */
 typedef void (*void_fn_t)();
 /* { from defs.h */
