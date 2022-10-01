--- examples/loadables/getconf.c.orig	2022-10-01 03:42:16 UTC
+++ examples/loadables/getconf.c
@@ -21,7 +21,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <error.h>
-#include <libintl.h>
+#include <gettext.h>
 #include <locale.h>
 #include <string.h>
 #include <stdlib.h>
