--- lib/snmpclient.c.orig	Thu Sep 22 09:07:57 2005
+++ lib/snmpclient.c	Thu Sep 22 09:08:38 2005
@@ -48,7 +48,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <netdb.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 #include <limits.h>
 #ifdef HAVE_ERR_H
 #include <err.h>
