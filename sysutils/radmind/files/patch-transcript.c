--- ./transcript.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./transcript.c	2014-06-29 12:15:04.249543651 +0200
@@ -45,7 +45,7 @@
 
 char				*path_prefix = NULL;
 int				edit_path;
-int				skip;
+int				skip = 0;
 int				cksum;
 int				fs_minus;
 int				exclude_warnings = 0;
@@ -271,7 +271,7 @@
 	tran->t_pinfo.pi_stat.st_mode = strtol( argv[ 2 ], NULL, 8 );
 	tran->t_pinfo.pi_stat.st_uid = atoi( argv[ 3 ] );
 	tran->t_pinfo.pi_stat.st_gid = atoi( argv[ 4 ] );
-	tran->t_pinfo.pi_stat.st_mtime = atoi( argv[ 5 ] );
+	tran->t_pinfo.pi_stat.st_mtime = strtotimet( argv[ 5 ], NULL, 10 );
 	tran->t_pinfo.pi_stat.st_size = strtoofft( argv[ 6 ], NULL, 10 );
 	if ( tran->t_type != T_NEGATIVE ) {
 	    if (( cksum ) && ( strcmp( "-", argv [ 7 ] ) == 0  )) {
@@ -436,12 +436,13 @@
 	 * but the corresponding transcript is negative, hence, retain
 	 * the file system's mtime.  Woof!
 	 */
-	fprintf( outtran, "%c %-37s\t%.4lo %5d %5d %9d %7" PRIofft "d %s\n",
+	fprintf( outtran, "%c %-37s\t%.4lo %5d %5d %9" PRItimet "d "
+			  "%7" PRIofft "d %s\n",
 		cur->pi_type, epath,
 		(unsigned long)( T_MODE & cur->pi_stat.st_mode ), 
 		(int)cur->pi_stat.st_uid, (int)cur->pi_stat.st_gid,
 		( flag == PR_STATUS_NEG ) ?
-			(int)fs->pi_stat.st_mtime : (int)cur->pi_stat.st_mtime,
+			fs->pi_stat.st_mtime : cur->pi_stat.st_mtime,
 		cur->pi_stat.st_size, cur->pi_cksum_b64 );
 	break;
 
@@ -723,7 +724,7 @@
 	    if ( begin_tran->t_type != T_SPECIAL &&
 		    t_exclude( begin_tran->t_pinfo.pi_name )) {
 		if ( exclude_warnings ) {
-		    fprintf( stderr, "Warning: excluding %s\n",
+		    printf( "#! Warning: excluding %s\n",
 				begin_tran->t_pinfo.pi_name );
 		}
 		transcript_parse( begin_tran );
@@ -769,7 +770,7 @@
 	    if ( list_size( special_list ) <= 0
 		    || list_check( special_list, path ) == 0 ) {
 		if ( exclude_warnings ) {
-		    fprintf( stderr, "Warning: excluding %s\n", path );
+		    printf( "#! Warning: excluding %s\n", path );
 		}
 
 		/* move the transcripts ahead */
@@ -949,7 +950,7 @@
      */
     t_new( T_NULL, NULL, NULL, NULL );
 
-    if ( skip ) {
+    if ( skip == T_SKIP_ALL ) {
 	return;
     }
 
@@ -985,15 +986,17 @@
 	exit( 2 );
     }
 
-    if (( list_size( special_list ) > 0 ) && ( location == K_CLIENT )) {
-	/* open the special transcript if there were any special files */
-	if ( strlen( kdir ) + strlen( special ) + 2 > MAXPATHLEN ) {
-	    fprintf( stderr, 
-		    "special path too long: %s%s\n", kdir, special );
-	    exit( 2 );
+    if ( !( skip & T_SKIP_SPECIAL )) {
+	if (( list_size( special_list ) > 0 ) && ( location == K_CLIENT )) {
+	    /* open the special transcript if there were any special files */
+	    if ( strlen( kdir ) + strlen( special ) + 2 > MAXPATHLEN ) {
+		fprintf( stderr, 
+			"special path too long: %s%s\n", kdir, special );
+		exit( 2 );
+	    }
+	    sprintf( fullpath, "%s%s", kdir, special );
+	    t_new( T_SPECIAL, fullpath, special, "special" );
 	}
-	sprintf( fullpath, "%s%s", kdir, special );
-	t_new( T_SPECIAL, fullpath, special, "special" );
     }
 
     if ( tran_head->t_type == T_NULL  && edit_path == APPLICABLE ) {
@@ -1108,6 +1111,10 @@
 	    break;
 
 	case 'n':				/* negative */
+	    if ( skip & T_SKIP_NEGATIVE ) {
+		break;
+	    }
+
 	    if ( minus ) { 
 		t_remove( T_NEGATIVE, av[ 1 ] );
 	    } else {
@@ -1116,6 +1123,10 @@
 	    break;
 
 	case 'p':				/* positive */
+	    if ( skip & T_SKIP_POSITIVE ) {
+		break;
+	    }
+
 	    if ( minus ) {
 		t_remove( T_POSITIVE, av[ 1 ] );
 	    } else {
@@ -1124,6 +1135,10 @@
 	    break;
 
 	case 'x':				/* exclude */
+	    if ( skip & T_SKIP_EXCLUDES ) {
+		break;
+	    }
+
 	    if (( d_pattern = decode( av[ 1 ] )) == NULL ) {
 		fprintf( stderr, "%s: line %d: decode buffer too small\n",
 		    kfile, linenum );
@@ -1149,6 +1164,10 @@
 	    break;
 
 	case 's':				/* special */
+	    if ( skip & T_SKIP_SPECIAL ) {
+		break;
+	    }
+
 	    path = av[ 1 ];
 
 	    /* Convert path to match transcript type */
