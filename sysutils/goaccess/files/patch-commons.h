--- ./commons.h.orig	2012-06-04 04:16:26.000000000 +0200
+++ ./commons.h	2012-08-08 20:30:36.000000000 +0200
@@ -35,6 +35,11 @@
 #ifndef COMMONS_H_INCLUDED
 #define COMMONS_H_INCLUDED
 
+/* off_t need sys/types.h on 7.x */
+#if __FreeBSD_cc_version_ < 700022
+#include <sys/types.h>
+#endif
+
 /* Remove the __attribute__ stuff when the compiler is not GCC. */
 #if !__GNUC__
 #  define __attribute__(x) /**/
