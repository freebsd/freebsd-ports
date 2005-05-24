--- libng/plugins/drv0-bsd.c.orig	Wed Mar 12 17:45:56 2003
+++ libng/plugins/drv0-bsd.c	Tue May 24 11:32:55 2005
@@ -23,10 +23,12 @@
 
 #ifdef HAVE_DEV_IC_BT8XX_H
 # include <dev/ic/bt8xx.h>
-#endif
-#ifdef HAVE_MACHINE_IOCTL_BT848_H
+#elif defined(HAVE_MACHINE_IOCTL_BT848_H)
 # include <machine/ioctl_bt848.h>
 # include <machine/ioctl_meteor.h>
+#else
+# include <dev/bktr/ioctl_bt848.h>
+# include <dev/bktr/ioctl_meteor.h>
 #endif
 
 #include "grab-ng.h"
@@ -127,7 +129,7 @@
     {  3, "CSVIDEO"      },
     { -1, NULL }
 };
-static int inputs_map[] = {
+static long inputs_map[] = {
     METEOR_INPUT_DEV1,
     METEOR_INPUT_DEV0,
     METEOR_INPUT_DEV_SVIDEO,
@@ -144,7 +146,7 @@
     {  6, "RSVD"      },
     { -1, NULL }
 };
-static int norms_map[] = {
+static long norms_map[] = {
     BT848_IFORM_F_NTSCM,
     BT848_IFORM_F_NTSCJ,
     BT848_IFORM_F_PALBDGHI,
@@ -160,7 +162,7 @@
     {  2, "Intern"      },
     { -1, NULL }
 };
-static int audio_map[] = {
+static long audio_map[] = {
     AUDIO_TUNER,
     AUDIO_EXTERN,
     AUDIO_INTERN,
@@ -242,7 +244,7 @@
 #define PREFIX "bktr: ioctl: "
 
 static int
-xioctl(int fd, int cmd, void *arg)
+xioctl(int fd, unsigned long cmd, void *arg)
 {
     int rc;
 
@@ -296,7 +298,7 @@
 	break;
     }
     default:
-	fprintf(stderr,PREFIX "UNKNOWN(cmd=0x%x)",cmd);
+	fprintf(stderr,PREFIX "UNKNOWN(cmd=0x%x)",(int)cmd);
 	break;
     }
     fprintf(stderr,": %s\n",(rc == 0) ? "ok" : strerror(errno));
@@ -474,7 +476,7 @@
 /* ---------------------------------------------------------------------- */
 
 static int
-bsd_get_range(int id, int *get, int *set)
+bsd_get_range(int id, int *get, long *set)
 {
     switch (id) {
     case ATTR_ID_HUE:
@@ -502,19 +504,20 @@
 static int bsd_read_attr(struct ng_attribute *attr)
 {
     struct bsd_handle *h = attr->handle;
-    int arg, get, set, i;
+    int get, i;
+    long arg, set;
     int value = -1;
 
     switch (attr->id) {
     case ATTR_ID_NORM:
 	if (-1 != xioctl(h->fd,BT848GFMT,&arg))
-	    for (i = 0; i < sizeof(norms_map)/sizeof(int); i++)
+	    for (i = 0; i < sizeof(norms_map)/sizeof(*norms_map); i++)
 		if (arg == norms_map[i])
 		    value = i;
 	break;
     case ATTR_ID_INPUT:
 	if (-1 != xioctl(h->fd,METEORGINPUT,&arg))
-	    for (i = 0; i < sizeof(inputs_map)/sizeof(int); i++)
+	    for (i = 0; i < sizeof(inputs_map)/sizeof(*inputs_map); i++)
 		if (arg == inputs_map[i])
 		    value = i;
 	break;
@@ -532,7 +535,7 @@
 	break;
     case ATTR_ID_COUNT+1: /* AUDIO */
 	if (-1 != xioctl(h->tfd, BT848_GAUDIO, &arg))
-	    for (i = 0; i < sizeof(audio_map)/sizeof(int); i++)
+	    for (i = 0; i < sizeof(audio_map)/sizeof(*audio_map); i++)
 		if (arg == audio_map[i])
 		    value = i;
 	break;
@@ -545,7 +548,8 @@
 static void bsd_write_attr(struct ng_attribute *attr, int value)
 {
     struct bsd_handle *h = attr->handle;
-    int arg, get, set;
+    int get;
+    long arg, set;
 
     switch (attr->id) {
     case ATTR_ID_NORM:
@@ -599,7 +603,15 @@
 
 static int bsd_tuned(void *handle)
 {
-    return 0;
+    struct bsd_handle *h = handle;
+    int signal;
+
+    usleep(10000);
+
+    if (-1 == xioctl(h->tfd, TVTUNER_GETSTATUS, &signal))
+	return 0;
+
+    return signal == 106 ? 1 : 0;
 }
 
 /* ---------------------------------------------------------------------- */
