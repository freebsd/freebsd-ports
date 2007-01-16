--- src/displayer.cc.orig	Tue Jan 16 01:52:01 2007
+++ src/displayer.cc	Tue Jan 16 01:55:59 2007
@@ -573,20 +573,23 @@
 			xvImage = ( XvImage * ) XvShmCreateImage( display, port, 0x32595559, 0, width, height, &shmInfo );
 
 			shmInfo.shmid = shmget( IPC_PRIVATE, xvImage->data_size, IPC_CREAT | 0777 );
-			shmInfo.shmaddr = ( char * ) shmat( shmInfo.shmid, 0, 0 );
-			xvImage->data = shmInfo.shmaddr;
-			shmInfo.readOnly = 0;
-			if ( !XShmAttach( gdk_display, &shmInfo ) )
-			{
+			if (shmInfo.shmid < 0) {
+				perror("shmget");
 				gotPort = false;
-			}
-			XSync( display, false );
-			shmctl( shmInfo.shmid, IPC_RMID, 0 );
+			} else {
+				shmInfo.shmaddr = ( char * ) shmat( shmInfo.shmid, 0, 0 );
+				xvImage->data = shmInfo.shmaddr;
+				shmInfo.readOnly = 0;
+				if ( !XShmAttach( gdk_display, &shmInfo ) )
+				{
+					gotPort = false;
+				}
+				XSync( display, false );
+				shmctl( shmInfo.shmid, IPC_RMID, 0 );
 #if 0
-
-			xvImage = ( XvImage * ) XvCreateImage( display, port, 0x32595559, pix, width , height );
+				xvImage = ( XvImage * ) XvCreateImage( display, port, 0x32595559, pix, width , height );
 #endif
-
+			}
 		}
 	}
 	else
