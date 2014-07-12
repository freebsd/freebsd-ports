--- ./fsdiff.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./fsdiff.c	2014-06-29 12:15:04.245544128 +0200
@@ -249,6 +249,144 @@
     return;
 }
 
+    static char *
+canonicalized_path( char *path )
+{
+    int			len;
+    static char		cpath[ MAXPATHLEN ];
+
+    if ( path == NULL ) {
+	return( NULL );
+    }
+
+    len = strlen( path );
+    if ( len >= sizeof( cpath )) {
+	fprintf( stderr, "fsdiff: path too long: %s\n", path );
+	exit( 2 );
+    }
+    strcpy( cpath, path );
+
+    /* Clip trailing '/' */
+    if (( len > 1 ) && ( cpath[ len - 1 ] == '/' )) {
+	cpath[ len - 1 ] = '\0';
+	len--;
+    }
+
+    /*
+     * If prefix doesn't contain a directory, canonicalize it by prepending a
+     * "./".  This allow paths to be dynamically converted between relative and
+     * absolute paths without breaking sort order.
+     */
+    switch( cpath[ 0 ] ) {
+    case '/':
+        break;
+
+    case '.':
+	/* Don't rewrite '.' or paths starting with './' */
+	if ( len == 1 || cpath[ 1 ] == '/' ) {
+	    break;
+	}
+
+    default:
+	if ( len + 2 >= sizeof( cpath )) {
+	    fprintf( stderr, "fsdiff: path too long: ./%s\n", cpath );
+	    exit( 2 );
+	}
+	memmove( cpath + 2, cpath, len );
+	cpath[ 0 ] = '.'; cpath[ 1 ] = '/';
+
+        break;
+    }
+
+    /*
+     * Determine if called with relative or absolute pathing.  Path is relative
+     * if it's just '.' or starts with './'.  File names that start with a '.'
+     * are absolute.
+     */
+    if ( cpath[ 0 ] == '.' ) {
+	if ( len == 1 ) {
+	    tran_format = T_RELATIVE;
+	} else if ( cpath[ 1 ] == '/' ) {
+	    tran_format = T_RELATIVE;
+	} else {
+	    tran_format = T_ABSOLUTE;
+	}
+    } else {
+	tran_format = T_ABSOLUTE;
+    }
+
+    return( cpath );
+}
+
+    static void
+fsdiff( char *path, char *kfile, int start, int finish, int pdel ) 
+{
+    struct applefileinfo	afinfo;
+    struct stat			st;
+    char			type;
+    char			lpath[ MAXPATHLEN ];
+    int				len;
+
+    if (( dotfd = open( ".", O_RDONLY, 0 )) < 0 ) {
+	perror( "OOPS!" );
+	exit( 2 );
+    }
+
+    if ( skip && strcmp( path, "-" ) == 0 ) {
+	/* leave excludes in place */
+	skip = skip & ~T_SKIP_EXCLUDES;
+
+	path_prefix = "/";
+	transcript_init( kfile, K_CLIENT );
+
+	/* run -1 against every line we get from stdin */
+	while ( fgets( lpath, sizeof( lpath ), stdin ) != NULL ) {
+	    len = strlen( lpath );
+	    if ( lpath[ len - 1 ] != '\n' ) {
+		fprintf( stderr, "fsdiff: fgets: line too long\n" );
+		exit( 2 );
+	    }
+	    lpath[ len - 1 ] = '\0';
+	    path = canonicalized_path( lpath );
+
+	    if ( radstat( path, &st, &type, &afinfo ) != 0 ) {
+		if ( errno != ENOENT ) {
+		    perror( lpath );
+		    exit( 2 );
+		}
+
+		fprintf( stderr, "Warning: %s: %s\n", path, strerror( errno ));
+		continue;
+	    }
+	    (void)transcript( path, &st, &type, &afinfo, pdel );
+	}
+	if ( ferror( stdin )) {
+	    perror( "fgets" );
+	    exit( 2 );
+	}
+    } else {
+	path_prefix = canonicalized_path( path );
+
+	/* initialize the transcripts */
+	transcript_init( kfile, K_CLIENT );
+
+	if ( radstat( path_prefix, &st, &type, &afinfo ) != 0 ) {
+	    perror( path_prefix );
+	    exit( 2 );
+	}
+
+	fs_walk( path_prefix, &st, &type, &afinfo, start, finish, pdel );
+    }
+
+    if ( finish > 0 ) {
+	printf( "%%%d\n", ( int )finish );
+    }
+
+    /* free the transcripts */
+    transcript_free( );
+    hardlink_free( );
+}
+
     int
 main( int argc, char **argv ) 
 {
@@ -258,9 +396,6 @@
     int 		c, len, edit_path_change = 0;
     int 		errflag = 0, use_outfile = 0;
     int			finish = 0;
-    struct stat		st;
-    char		type, buf[ MAXPATHLEN ];
-    struct applefileinfo	afinfo;
 
     edit_path = CREATABLE;
     cksum = 0;
@@ -300,7 +435,7 @@
 	    break;
 
 	case '1':
-	    skip = 1;
+	    skip = T_SKIP_ALL;
 	case 'C':
 	    edit_path_change++;
 	    edit_path = CREATABLE;
@@ -347,82 +482,13 @@
     }
 
     if ( errflag || ( argc - optind != 1 )) {
-	fprintf( stderr, "usage: %s { -C | -A | -1 } [ -IVW ] ", argv[ 0 ] );
+	fprintf( stderr, "usage: %s { -C | -A | -1 } " "[ -IVW ] ", argv[ 0 ] );
 	fprintf( stderr, "[ -K command ] " );
 	fprintf( stderr, "[ -c checksum ] [ -o file [ -%% ] ] path\n" );
 	exit ( 2 );
     }
 
-    path_prefix = argv[ optind ];
-    len = strlen( path_prefix );
-
-    /* Clip trailing '/' */
-    if (( len > 1 ) && ( path_prefix[ len - 1 ] == '/' )) {
-	path_prefix[ len - 1 ] = '\0';
-	len--;
-    }
-
-    /* If path_prefix doesn't contain a directory, canonicalize it by
-     * prepending a "./".  This allow paths to be dynamically converted between
-     * relative and absolute paths without breaking sort order.
-     */
-    switch( path_prefix[ 0 ] ) {
-    case '/':
-        break;
-
-    case '.':
-	/* Don't rewrite '.' or paths starting with './' */
-	if (( len == 1 ) || (  path_prefix[ 1 ] == '/' )) {
-	    break;
-	}
-    default:
-        if ( snprintf( buf, sizeof( buf ), "./%s",
-                path_prefix ) >= MAXPATHLEN ) {
-            fprintf( stderr, "path too long\n" );
-            exit( 2 );
-        }
-	path_prefix = buf;
-        break;
-    }
-
-    /* Determine if called with relative or absolute pathing.  Path is relative
-     * if it's just '.' or starts with './'.  File names that start with a '.'
-     * are absolute.
-     */
-    if ( path_prefix[ 0 ] == '.' ) {
-	if ( len == 1 ) {
-	    tran_format = T_RELATIVE;
-	} else if ( path_prefix[ 1 ] == '/' ) {
-	    tran_format = T_RELATIVE;
-	} else {
-	    tran_format = T_ABSOLUTE;
-	}
-    } else {
-	tran_format = T_ABSOLUTE;
-    }
-
-    if ( radstat( path_prefix, &st, &type, &afinfo ) != 0 ) {
-	perror( path_prefix );
-	exit( 2 );
-    }
-
-    if (( dotfd = open( ".", O_RDONLY, 0 )) < 0 ) {
-	perror( "OOPS!" );
-	exit( 2 );
-    }
-
-    /* initialize the transcripts */
-    transcript_init( kfile, K_CLIENT );
-
-    fs_walk( path_prefix, &st, &type, &afinfo, 0, finish, 0 );
-
-    if ( finish > 0 ) {
-	printf( "%%%d\n", ( int )finish );
-    }
-
-    /* free the transcripts */
-    transcript_free( );
-    hardlink_free( );
+    fsdiff( argv[ optind ], kfile, 0, finish, 0 );
 
     /* close the output file */     
     fclose( outtran );
