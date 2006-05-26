--- mediastreamer2/oss.c.orig	Fri Mar 24 18:30:55 2006
+++ mediastreamer2/oss.c	Sat Apr  1 01:00:49 2006
@@ -30,7 +30,10 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 
 MSFilter *ms_oss_read_new(MSSndCard *card);
 MSFilter *ms_oss_write_new(MSSndCard *card);
