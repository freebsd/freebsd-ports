--- pcre/internal.h.orig	Thu Sep 18 21:59:10 2003
+++ pcre/internal.h	Thu Sep 18 21:59:30 2003
@@ -38,6 +38,9 @@
 /* Get the definitions provided by running "configure" */
 
 #include "config.h"
+#include <ctype.h>
+#include <stdlib.h>
+#include <string.h>
 
 /* To cope with SunOS4 and other systems that lack memmove() but have bcopy(),
 define a macro for memmove() if HAVE_MEMMOVE is false, provided that HAVE_BCOPY
