--- toys/other/chvt.c.orig	2021-12-02 04:45:52 UTC
+++ toys/other/chvt.c
@@ -18,16 +18,17 @@ config CHVT
 */
 
 #include "toys.h"
-#include <linux/vt.h>
 
 void chvt_main(void)
 {
-  int vt, fd;
+  int vtnum, fd = fd;
   char *consoles[]={"/dev/console", "/dev/vc/0", "/dev/tty", NULL}, **cc;
 
-  vt = atoi(*toys.optargs);
-  for (cc = consoles; *cc; cc++) if ((fd = open(*cc, O_RDWR)) != -1) break;
+  vtnum=atoi(*toys.optargs);
+  for (cc = consoles; *cc; cc++)
+    if (-1 != (fd = open(*cc, O_RDWR))) break;
 
-  if (fd == -1 || ioctl(fd, VT_ACTIVATE, vt) || ioctl(fd, VT_WAITACTIVE, vt))
+  // These numbers are VT_ACTIVATE and VT_WAITACTIVE from linux/vt.h
+  if (!*cc || fd < 0 || ioctl(fd, 0x5606, vtnum) || ioctl(fd, 0x5607, vtnum))
     perror_exit(0);
 }
