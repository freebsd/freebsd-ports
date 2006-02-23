--- libMGPM/src/MGPMrGetPortName.c.orig	Thu Feb 23 03:04:28 2006
+++ libMGPM/src/MGPMrGetPortName.c	Thu Feb 23 03:06:22 2006
@@ -180,7 +180,8 @@
 			}
 			else
 			{
-				fclose( property->STDIN );
+				if( property->autoMoved == 0 )
+                                       fclose( property->STDIN );
 				MGPMlogAdd( property, "installed ", portName,
 					" removed from system:  no longer in ports tree:  see /usr/ports/MOVED", " ", " " );
 			}
