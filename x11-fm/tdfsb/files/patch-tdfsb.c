--- ./tdfsb.c.orig	2007-06-22 14:43:02.000000000 +0200
+++ ./tdfsb.c	2013-05-03 22:58:48.944863278 +0200
@@ -2795,7 +2795,7 @@
                             {
                                 strcpy(TDFSB_CURRENTPATH,temp_trunc);        
                                 TDFSB_FUNC_IDLE=nullDisplay; TDFSB_FUNC_DISP=noDisplay; 
-                                return;
+                                return(0);
                             }
 			    TDFSB_FUNC_IDLE=nullDisplay;
                             TDFSB_FUNC_DISP=noDisplay;
