--- a/usbredirtestclient/usbredirtestclient.c
+++ b/usbredirtestclient/usbredirtestclient.c
@@ -33,6 +33,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include "usbredirparser.h"
 
 /* Macros to go from an endpoint address to an index for our ep array */
