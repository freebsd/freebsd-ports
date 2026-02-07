--- slirpvde/libslirp.h	Sat Jan 29 15:02:08 2005
+++ slirpvde/libslirp.h	Sun Jan 30 13:55:31 2005
@@ -2,7 +2,11 @@
 #define _LIBSLIRP_H
 
 #include <sys/select.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#else
 #include <stdint.h>
+#endif
 
 void slirp_init(char *network);
 
