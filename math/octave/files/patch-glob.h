--- glob/glob.h.orig	Sun Nov 10 15:32:00 2002
+++ glob/glob.h	Sun Nov 10 15:32:49 2002
@@ -48,7 +48,11 @@
 /* We need `size_t' for the following definitions.  */
 #ifndef __size_t
 # if defined __GNUC__ && __GNUC__ >= 2
+#ifndef __FreeBSD__
 typedef __SIZE_TYPE__ __size_t;
+#else
+#include <sys/types.h>
+#endif
 # else
 /* This is a guess.  */
 /*hb
