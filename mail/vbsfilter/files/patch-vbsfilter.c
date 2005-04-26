--- vbsfilter-1.15.c.orig
+++ vbsfilter-1.15.c
@@ -14,6 +14,11 @@
 #include <sysexits.h>
 #include <termios.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#include <netdb.h>
+#include <unistd.h>
+#endif
 #include "libmilter/mfapi.h"
 
 /*
