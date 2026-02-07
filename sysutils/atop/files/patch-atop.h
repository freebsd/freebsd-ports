--- atop.h.orig	2014-01-15 16:05:34 UTC
+++ atop.h
@@ -49,6 +49,11 @@ struct netpertask;
 #define RRNETATOP	0x0004
 #define RRNETATOPD	0x0008
 
+#include <sys/param.h>
+#if __FreeBSD_version > 1100116
+#define P_KTHREAD P_KPROC
+#endif
+
 struct visualize {
 	char	(*show_samp)  (time_t, int,
 	                struct sstat *, struct tstat *, struct tstat **,
