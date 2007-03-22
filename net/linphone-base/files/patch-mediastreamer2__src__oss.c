--- mediastreamer2/src/oss.c.orig	Thu Nov  9 19:45:26 2006
+++ mediastreamer2/src/oss.c	Wed Dec 27 23:57:46 2006
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
