--- prayer/prayer_chroot.c.orig	2006-04-11 15:29:26.000000000 +0100
+++ prayer/prayer_chroot.c	2008-01-09 16:26:45.000000000 +0000
@@ -10,8 +10,6 @@
 #include "prayer.h"
 #include "prayer_server.h"
 
-#include <sys/prctl.h>
-
 BOOL prayer_main_use_existing(struct prayer *prayer, char *ports)
 {
     char *use_ssl, *fd, *next;
@@ -305,7 +303,6 @@
         if (getuid() == 0)
             log_fatal("Failed to lose root priveledges");       /* Stop impossible loop */
 
-        prctl(PR_SET_DUMPABLE, 1);
     }
 
     if (getuid() == 0)
