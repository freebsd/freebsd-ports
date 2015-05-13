--- a/libsi/si.c
+++ b/libsi/si.c
@@ -13,7 +13,9 @@
 #include "si.h"
 #include <errno.h>
 #include <iconv.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <stdlib.h> // for broadcaster stupidity workaround
 #include <string.h>
 #include "descriptor.h"
