--- src/File.h.bak	Thu Jun 24 23:55:59 2004
+++ src/File.h	Thu Jun 24 23:56:17 2004
@@ -24,6 +24,7 @@
 #ifdef HAVE_CONFIG_H
 #   include "../config.h"
 #endif
+#include <sys/stat.h>
 #include "Mailbox.h"
 
 
