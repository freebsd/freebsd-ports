--- src/main.c.old	Sun Sep 23 09:57:23 2001
+++ src/main.c	Sun Sep 23 09:57:49 2001
@@ -2,7 +2,10 @@
 #include "gnutella.h"
 
 #include <signal.h>
+
+#ifdef HAVE_MCHECK_H
 #include <mcheck.h>
+#endif
 
 #include "interface.h"
 #include "support.h"
