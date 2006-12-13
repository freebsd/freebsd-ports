--- ./libMGPM/src/MGPMrReadConfigure.c.orig	Wed Dec 14 00:12:40 2005
+++ ./libMGPM/src/MGPMrReadConfigure.c	Fri Dec  8 17:13:00 2006
@@ -156,7 +156,7 @@
 
 		MGmStrcpy( cmd[0], "/bin/cp" );
 		MGmStrcpy( cmd[1], property->configConfFileName );
-		MGmStrcat( cmd[1], ".SAMPLE " );
+		MGmStrcat( cmd[1], ".SAMPLE" );
 		MGmStrcpy( cmd[2], property->configConfFileName );
 
 		MGmSystem( cmd, NULL );
