--- shell.c.orig	Sun Sep 28 01:24:33 2003
+++ shell.c	Sun Sep 28 01:25:16 2003
@@ -43,7 +43,7 @@
 #include "bashansi.h"
 
 #if defined (HAVE_VARARGS_H)
-#include <varargs.h>
+#include <stdarg.h>
 #endif
 
 #include "shell.h"
