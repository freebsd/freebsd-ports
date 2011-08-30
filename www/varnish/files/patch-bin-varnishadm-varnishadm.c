--- bin/varnishadm/varnishadm.c.orig	2011-08-29 10:45:24.000000000 +0200
+++ bin/varnishadm/varnishadm.c	2011-08-30 23:33:47.000000000 +0200
@@ -38,8 +38,12 @@
 #include <sys/socket.h>
 
 #ifdef HAVE_LIBEDIT
+#ifdef __FreeBSD__
+#include <readline/readline.h>
+#else
 #include <editline/readline.h>
 #endif
+#endif
 
 #include "vcli.h"
 #include "cli_common.h"
