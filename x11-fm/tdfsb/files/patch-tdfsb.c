--- tdfsb.c.orig	2007-06-22 12:43:02 UTC
+++ tdfsb.c
@@ -2795,7 +2795,7 @@ int keyboard (unsigned char key)
                             {
                                 strcpy(TDFSB_CURRENTPATH,temp_trunc);        
                                 TDFSB_FUNC_IDLE=nullDisplay; TDFSB_FUNC_DISP=noDisplay; 
-                                return;
+                                return(0);
                             }
 			    TDFSB_FUNC_IDLE=nullDisplay;
                             TDFSB_FUNC_DISP=noDisplay;
