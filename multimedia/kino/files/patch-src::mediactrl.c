--- src/mediactrl.c.orig	Tue Jul 13 02:46:15 2004
+++ src/mediactrl.c	Fri Aug 13 01:26:56 2004
@@ -19,14 +19,14 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/time.h>
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
 
 
@@ -101,7 +101,7 @@
 	Griffin PowerMate
 */
 static struct media_ctrl_key mc_powermate_keys[] = {
-	{ BTN_0, "Button", MEDIA_CTRL_B1 },
+	{ 0xdead, "Button", MEDIA_CTRL_B1 },
 	{ 0, NULL, 0 }
 };
 
@@ -126,6 +126,7 @@
 
 void translate_contour_hid_event(struct media_ctrl *ctrl, struct input_event *ev, struct media_ctrl_event *me) 
 {
+#if 0
 	
 	int lv, cv;
 	
@@ -183,10 +184,12 @@
 		
 	}
 	
+#endif
 }
 
 void translate_compliant(struct media_ctrl *ctrl, struct input_event *ev, struct media_ctrl_event *me) 
 {
+#if 0
 	me->type = 0;
 	
 	// printf("Translate %02x %02x\n", ev->type, ev->code );
@@ -227,6 +230,7 @@
 		//printf("Key: %04x %02x: %s\n", ev->code, ev->value, key->name);
 		
 	}
+#endif
 }
 
 struct media_ctrl_device supported_devices[] = {
@@ -273,8 +277,9 @@
 	
 	if ( me->type  == MEDIA_CTRL_EVENT_JOG ) {
 		struct timeval timev;
+		unsigned long now;
 		gettimeofday(&timev, NULL);
-		unsigned long now = (unsigned long)timev.tv_usec + (1000000*(unsigned long)timev.tv_sec);
+		now = (unsigned long)timev.tv_usec + (1000000*(unsigned long)timev.tv_sec);
 		if ( now < ctrl->last_jog_time + 40000 ) {
 			//printf("*** Fast Jog %02d %05d ***\n", me->value, now - ctrl->last_jog_time);
 			ctrl->jogrel = me->value;
@@ -294,6 +299,7 @@
 
 int probe_device(struct media_ctrl *mc)
 {
+#if 0
 	short devinfo[4];
 	int i = 0;
 	  
@@ -321,6 +327,7 @@
 	
 	} while ( supported_devices[++i].vendor != 0 );
 			
+#endif
 	return 0;
 }
 
