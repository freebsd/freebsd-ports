--- src/mediactrl.c.orig	Mon Mar 15 23:21:57 2004
+++ src/mediactrl.c	Tue Apr 13 11:10:03 2004
@@ -18,14 +18,14 @@
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <asm/types.h>
+//#include <asm/types.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <stdint.h>
+//#include <stdint.h>
 #include <string.h>
 #include <errno.h>
 
-#include <linux/input.h>
+//#include <linux/input.h>
 #include "mediactrl.h"
 
 
@@ -119,6 +119,7 @@
 
 void translate_contour_hid_event(struct media_ctrl *ctrl, struct input_event *ev, struct media_ctrl_event *me) 
 {
+#if 0
 	
 	int lv, cv;
 	
@@ -176,10 +177,12 @@
 		
 	}
 	
+#endif
 }
 
 void translate_compliant(struct media_ctrl *ctrl, struct input_event *ev, struct media_ctrl_event *me) 
 {
+#if 0
 	me->type = 0;
 	
 	// printf("Translate %02x %02x\n", ev->type, ev->code );
@@ -220,6 +223,7 @@
 		//printf("Key: %04x %02x: %s\n", ev->code, ev->value, key->name);
 		
 	}
+#endif
 }
 
 struct media_ctrl_device supported_devices[] = {
@@ -264,8 +268,9 @@
 	
 	if ( me->type  == MEDIA_CTRL_EVENT_JOG ) {
 		struct timeval timev;
+		unsigned long now;
 		gettimeofday(&timev, NULL);
-		unsigned long now = (unsigned long)timev.tv_usec + (1000000*(unsigned long)timev.tv_sec);
+		now = (unsigned long)timev.tv_usec + (1000000*(unsigned long)timev.tv_sec);
 		if ( now < ctrl->last_jog_time + 40000 ) {
 			//printf("*** Fast Jog %02d %05d ***\n", me->value, now - ctrl->last_jog_time);
 			ctrl->jogrel = me->value;
@@ -285,6 +290,7 @@
 
 int probe_device(struct media_ctrl *mc)
 {
+#if 0
 	short devinfo[4];
 	int i = 0;
 	  
@@ -312,6 +318,7 @@
 	
 	} while ( supported_devices[++i].vendor != 0 );
 			
+#endif
 	return 0;
 }
 
