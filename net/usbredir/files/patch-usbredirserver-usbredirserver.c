--- a/usbredirserver/usbredirserver.c
+++ b/usbredirserver/usbredirserver.c
@@ -33,6 +33,9 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include "usbredirhost.h"
 
 #define VERSION "usbredirserver " USBREDIR_VERSION
