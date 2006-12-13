--- ./libMGPM/src/MGPMrPortBrokeCheck.c.orig	Tue Dec 13 17:08:27 2005
+++ ./libMGPM/src/MGPMrPortBrokeCheck.c	Fri Dec  8 17:13:00 2006
@@ -78,7 +78,7 @@
 	}
 	buffer[0]	= 0;
 	fread( buffer, MAXBUFFERSIZE, 1, pHandle );
-	if( ferror( pHandle ) == 0 && MGrStrlen( buffer ) > 1 )
+	if( ferror( pHandle ) == 0 && MGrBufferlen( buffer, MAXBUFFERSIZE ) > 1 )
 	{
 		fprintf( stdout, "%s %s error: %s %s marked %s, adding to ignore.db\n", id, PACKAGE_VERSION, oldPortName, oldPortDir, brokeCheckType );
 		while( fflush( stdout ) );
