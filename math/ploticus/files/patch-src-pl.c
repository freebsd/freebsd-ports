--- src/pl.c.orig	2008-09-03 00:53:46.000000000 -0500
+++ src/pl.c	2008-09-03 00:54:16.000000000 -0500
@@ -151,7 +151,7 @@
 
 	else if( strcmp( arg, "-f" )==0 ) {
 		if( strlen( nextarg ) > MAXPATH-10 ) { /* allow extra for output file suffix add */
-			fprintf( PLS.errfp, "pl: script file name too long" );
+			fprintf( PLS.errfp, "ploticus: script file name too long" );
 			PL_version_msg( 0 ); exit( 1 );
 			}
 		strcpy( scriptfile, nextarg );
@@ -180,7 +180,7 @@
 		if( !found && arg[0] == '-' ) Eerr( 4892, "warning, unrecognized argument", arg );
 		else if( !found && scriptfile[0] == '\0' ) {
 			if( strlen( arg ) > MAXPATH-10 ) { /* allow extra for output file suffix add */
-				fprintf( PLS.errfp, "pl: script file name too long" );
+				fprintf( PLS.errfp, "ploticus: script file name too long" );
 				PL_version_msg( 0 ); exit( 1 );
 				}
 			strcpy( scriptfile, arg  );  
@@ -228,7 +228,7 @@
 	
 
 if( scriptfile[0] == '\0' ) {
-	fprintf( PLS.diagfp, "usage: pl scriptfile [options] ...or...  pl -prefab prefabname [options]\n" );
+	fprintf( PLS.diagfp, "usage: ploticus scriptfile [options] ...or...  ploticus -prefab prefabname [options]\n" );
 	PL_version_msg( 0 );
 	}
 
