--- secmem/secmem.c.orig	Thu Jan 30 07:50:34 2003
+++ secmem/secmem.c	Thu Jan 30 07:50:41 2003
@@ -42,6 +42,7 @@
 #else /* ORIGINAL_GPG_VERSION */
 
 #include <sys/types.h>
+#include "../jnlib/types.h"
 
 typedef union {
     int a;
