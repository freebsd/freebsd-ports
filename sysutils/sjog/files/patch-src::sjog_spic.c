--- src/sjog_spic.c.orig	Mon Aug  6 13:38:14 2001
+++ src/sjog_spic.c	Sat Aug 17 20:38:56 2002
@@ -1,9 +1,17 @@
+/* FreeBSD modifications by Jay Kuri jk@oneway.com 08/13/01 */
+
 #include "sjog_spic.h"
+#ifdef __FreeBSD__
+#include "sonypi.h"
+#endif
 
 void
 sjog_spic_init()
 {
 
+#ifdef __FreeBSD__
+   spic_init();
+#else
    /* open spic device */
    if ((spic_fd = open(SPIC_DEVICE, O_RDONLY)) < 0)
    {
@@ -11,6 +19,7 @@
               SPIC_DEVICE);
       exit(1);
    }
+#endif
 
 }
 
@@ -24,12 +33,16 @@
    fprintf(stdout, "sjog_spic_read_jog: spic_fd=%d\n", spic_fd);
 #endif
 
+#ifdef __FreeBSD__
+      jog = spic_jogger_turned();
+#else
    if (read(spic_fd, (gchar *) & jog, sizeof(gint)) < 0)
    {
       fprintf(stderr, "%s read error!\n", SPIC_DEVICE);
       close(spic_fd);
       exit(1);
    }
+#endif
 
    sjog_jog_position_changed(jog);
 
