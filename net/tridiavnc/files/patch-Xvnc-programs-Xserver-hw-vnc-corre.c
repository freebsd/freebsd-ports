--- Xvnc/programs/Xserver/hw/vnc/corre.c.orig	2000-04-12 11:18:32.000000000 -0700
+++ Xvnc/programs/Xserver/hw/vnc/corre.c	2013-10-30 23:32:20.000000000 -0700
@@ -63,14 +63,14 @@
 	rfbSendRectEncodingCoRRE(cl, x, y, w, cl->correMaxHeight  );
 	rfbSendRectEncodingCoRRE(cl, x, y + cl->correMaxHeight, w,
 				 h - cl->correMaxHeight);
-	return;
+	return(0);
     }
 
     if (w > cl->correMaxWidth) {
 	rfbSendRectEncodingCoRRE(cl, x, y, cl->correMaxWidth, h);
 	rfbSendRectEncodingCoRRE(cl, x + cl->correMaxWidth, y,
 				 w - cl->correMaxWidth, h);
-	return;
+	return(0);
     }
 
     rfbSendSmallRectEncodingCoRRE(cl, x, y, w, h);
