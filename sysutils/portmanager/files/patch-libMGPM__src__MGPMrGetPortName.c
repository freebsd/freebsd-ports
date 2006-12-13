--- ./libMGPM/src/MGPMrGetPortName.c.orig	Wed Dec 14 10:27:41 2005
+++ ./libMGPM/src/MGPMrGetPortName.c	Fri Dec  8 17:13:00 2006
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
