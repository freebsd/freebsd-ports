--- prism2ctl/prism2ctl.c.orig	Sat Jul  6 15:27:53 2002
+++ prism2ctl/prism2ctl.c	Sat Jul  6 15:28:10 2002
@@ -50,7 +50,7 @@
 #include <sys/time.h>
 #include <net/if.h>
 
-#include <bat/common.h>
+#include <dev/wi/if_wavelan_ieee.h>
 
 #include <string.h>
 #include <unistd.h>
