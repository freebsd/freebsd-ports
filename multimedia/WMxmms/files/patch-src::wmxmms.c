--- src/wmxmms.c.orig	Thu Apr 10 17:13:16 2003
+++ src/wmxmms.c	Thu Apr 10 17:16:26 2003
@@ -218,14 +218,12 @@
 static void unhighlight_button(int x, int y, int b) {
 
 	int z;
-	int q;
-	
-	q = 25;
-	
+	int q = 25;
+
+	XmmsInfos *xmms = &cur_xmms_infos;
 
 	if( backlight == LIGHTON) 
 		q = 0;
-	XmmsInfos *xmms = &cur_xmms_infos;
 
         xmms->running = XmmsStatus();			       
 
