--- src/dvdcompile.c.orig       Sat Dec  6 04:44:53 2003
+++ src/dvdcompile.c    Wed Dec 17 01:51:22 2003
@@ -20,7 +20,9 @@
 #include "config.h"
 
 #include <stdio.h>
+#ifdef HAVE_STDINT
 #include <stdint.h>
+#endif
 
 #include "dvdauthor.h"
 #include "da-internal.h"
