--- Mailbox.c.orig	Sun Sep  8 01:54:37 2002
+++ Mailbox.c	Sun Sep  8 01:54:50 2002
@@ -75,7 +75,7 @@
 #ifdef linux
 #include <linux/soundcard.h>
 #else
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #endif /* ifdef linux */
 
 #define DEV_MIXER		"/dev/mixer"
