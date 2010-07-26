--- lsusb.c.orig	2009-08-17 22:28:42.000000000 +0000
+++ lsusb.c	2010-07-26 13:08:52.000000000 +0000
@@ -31,8 +31,11 @@
 #include <string.h>
 #include <errno.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <stdarg.h>
-#include <byteswap.h>
+#if defined(HAVE_UNISTD_H)
+#include <unistd.h>
+#endif
 #include <usb.h>
 
 #include "names.h"
