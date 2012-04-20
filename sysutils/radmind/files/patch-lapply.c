--- ./lapply.c.orig	2010-12-12 22:42:49.000000000 -0500
+++ ./lapply.c	2012-03-20 14:37:54.000000000 -0400
@@ -651,27 +651,37 @@
 filechecklist:
 		if ( head == NULL ) {
 		    if ( unlink( path ) != 0 ) {
-			perror( path );
-			goto error2;
-		    }
-		    if ( !quiet && !showprogress ) {
-			printf( "%s: deleted\n", path );
-		    }
-		    if ( showprogress ) {
-			progressupdate( PROGRESSUNIT, path );
-		    }
-		} else {
-		    if ( ischildcase( path, head->path, case_sensitive )) {
-			if ( unlink( path ) != 0 ) {
+			if ( !force || errno != ENOENT ) {
 			    perror( path );
 			    goto error2;
 			}
+			fprintf( stderr, "Warning: failed to remove %s: %s\n",
+				path, strerror( errno ));
+		    } else {
 			if ( !quiet && !showprogress ) {
 			    printf( "%s: deleted\n", path );
 			}
 			if ( showprogress ) {
 			    progressupdate( PROGRESSUNIT, path );
 			}
+		    }
+		} else {
+		    if ( ischildcase( path, head->path, case_sensitive )) {
+			if ( unlink( path ) != 0 ) {
+			    if ( !force || errno != ENOENT ) {
+				perror( path );
+				goto error2;
+			    }
+			    fprintf( stderr, "Warning: failed to remove %s: "
+				    "%s\n", path, strerror( errno ));
+			} else {
+			    if ( !quiet && !showprogress ) {
+				printf( "%s: deleted\n", path );
+			    }
+			    if ( showprogress ) {
+				progressupdate( PROGRESSUNIT, path );
+			    }
+			}
 		    } else {
 			/* remove head */
 			if ( rmdir( head->path ) != 0 ) {
