--- a/receiver.c
+++ b/receiver.c
@@ -32,7 +32,9 @@
 
 #include <vdr/remux.h>
 #include <vdr/channels.h>
+#ifndef __FreeBSD__
 #include <asm/byteorder.h>
+#endif
 
 #include "config.h"
 #include "receiver.h"
