--- gstopd.c.orig	2004-03-24 10:25:33 UTC
+++ gstopd.c
@@ -115,7 +115,7 @@ main(int argc, char **argv)
 		if( error != 0 ) {
 			errx( 1, "Error %d accessing %s", errno, path );
 		}
-		snprintf( devs[i].name, 6, argv[i] ); 
+		snprintf( devs[i].name, 6, "%s", argv[i] ); 
 		devs[i].lastt = 1;
 	}
 	error = daemon( 0, 0 );
