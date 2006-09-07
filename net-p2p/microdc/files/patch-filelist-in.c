--- src/filelist-in.c-orig     Wed Sep 21 23:28:10 2005
+++ src/filelist-in.c  Fri Aug 11 23:21:51 2006
@@ -20,6 +20,7 @@
 #include <config.h>
 #include <unistd.h>
 #include <sys/signal.h>
+#include <sys/stat.h>
 #include <stdbool.h>
 #include "gettext.h"            /* Gnulib/GNU gettext */
 #define _(s) gettext(s)
