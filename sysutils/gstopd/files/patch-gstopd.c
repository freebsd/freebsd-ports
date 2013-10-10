--- gstopd.c.orig	2013-10-10 12:51:01.431793192 +0000
+++ gstopd.c	2013-10-10 12:58:54.538750707 +0000
@@ -116,5 +116,5 @@
 			errx( 1, "Error %d accessing %s", errno, path );
 		}
-		snprintf( devs[i].name, 6, argv[i] ); 
+		snprintf( devs[i].name, 6, "%s", argv[i] ); 
 		devs[i].lastt = 1;
 	}
