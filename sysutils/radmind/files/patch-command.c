--- ./command.c.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./command.c	2014-06-29 12:15:04.244544161 +0200
@@ -477,38 +477,90 @@
 
 /* looks for special file info in transcripts */
     char **
-special_t( char *transcript, char *epath )
+special_t( char *sp_path, char *remote_path )
 {
-    FILE		*fs;
-    int			ac, len;
-    char		**av;
+    FILE		*fs = NULL;
+    int			i, ac, len, ln;
+    char		**av = NULL;
+    char		*paths[ 4 ] = { NULL };
+    char		*p;
+    char		sp_t[ MAXPATHLEN ];
     static char		line[ MAXPATHLEN ];
 
-    if (( fs = fopen( transcript, "r" )) == NULL ) {
-	return( NULL );
-    }
+    /*
+     * in order, we look for special file transcript lines in the
+     * following locations:
+     *
+     *      - A transcript in the same directory and with the same name
+     *	      as the special file, but with a ".T" extension.
+     *
+     *      - A transcript named "<remote_id>.T" in the same directory as
+     *        the client's special file directory root.
+     *
+     *      - /var/radmind/transcript/special.T
+     *
+     * if no matching transcript line is found, default metadata is
+     * returned to the client (type: f; mode: 0444; owner: 0; group: 0).
+     */
+    paths[ 0 ] = sp_path;
+    paths[ 1 ] = special_dir;
+    paths[ 2 ] = "transcript/special.T";
+    paths[ 3 ] = NULL;
 
-    while ( fgets( line, MAXPATHLEN, fs ) != NULL ) {
-	len = strlen( line );
-	if (( line[ len - 1 ] ) != '\n' ) {
-	    syslog( LOG_ERR, "special_t: %s: line too long", transcript );
-	    break;
+    for ( i = 0; paths[ i ] != NULL; i++ ) {
+	if (( p = strrchr( paths[ i ], '.' )) != NULL
+		&& strcmp( p, ".T" ) == 0 ) {
+	    if ( strlen( paths[ i ] ) >= MAXPATHLEN ) {
+		syslog( LOG_WARNING, "special_t: path \"%s\" too long",
+			paths[ i ] );
+		continue;
+	    }
+	    strcpy( sp_t, paths[ i ] );
+	} else if ( snprintf( sp_t, MAXPATHLEN, "%s.T",
+			      paths[ i ] ) >= MAXPATHLEN ) {
+	    syslog( LOG_WARNING, "special_t: path \"%s.T\" too long", sp_path );
+	    continue;
 	}
 
-	if (( ac = argcargv( line, &av )) != 8 ) {
+	if (( fs = fopen( sp_t, "r" )) == NULL ) {
 	    continue;
 	}
-	if (( *av[ 0 ] != 'f' ) && ( *av[ 0 ] != 'a' )) {
-	    continue;
+
+	ln = 0;
+	while ( fgets( line, MAXPATHLEN, fs ) != NULL ) {
+	    ln++;
+	    len = strlen( line );
+	    if (( line[ len - 1 ] ) != '\n' ) {
+		syslog( LOG_ERR, "special_t: %s: line %d too long", sp_t, ln );
+		break;
+	    }
+
+	    /* only files and applefiles allowed */
+	    if ( strncmp( line, "f ", strlen( "f " )) != 0 &&
+			strncmp( line, "a ", strlen( "a " )) != 0 ) {
+		continue;
+	    }
+	    if (( ac = argcargv( line, &av )) != 8 ) {
+		syslog( LOG_WARNING, "special_t: %s: line %d: "
+			"bad transcript line", sp_t, ln );
+		continue;
+	    }
+
+	    if ( strcmp( av[ 1 ], remote_path ) == 0 ) { 
+		(void)fclose( fs );
+		return( av );
+	    }
 	}
 
-	if ( strcmp( av[ 1 ], epath ) == 0 ) { 
-	    (void)fclose( fs );
-	    return( av );
+	if ( fclose( fs ) != 0 ) {
+	    syslog( LOG_WARNING, "special_t: fclose %s: %m", sp_t );
 	}
+	fs = NULL;
     }
-
-    (void)fclose( fs );
+    if ( fs != NULL ) {
+	(void)fclose( fs );
+    }
+    
     return( NULL );
 }
 
@@ -624,11 +676,11 @@
     switch ( key ) {
     case K_COMMAND:
 	if ( ac == 2 ) {
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	    snet_writef( sn, RADMIND_STAT_FMT,
 		"f", "command", DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
 	} else {
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	    snet_writef( sn, RADMIND_STAT_FMT,
 		"f", av[ 2 ], DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
 	}
@@ -636,61 +688,33 @@
         
 		    
     case K_TRANSCRIPT:
-	snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	snet_writef( sn, RADMIND_STAT_FMT,
 		"f", av[ 2 ], 
 		DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
 	return( 0 );
     
     case K_SPECIAL:
-	/*  status on a special file comes from 1 of three cases:
-	 *  1. A transcript in the special file directory
-	 *  2. A transcript in the Transcript dir with .T appended
-	 *  3. No transcript is found, and constants are returned
-	 */
-
-        /* look for transcript containing the information */
-	if ( ( strlen( path ) + 2 ) > MAXPATHLEN ) {
-	    syslog( LOG_WARNING, 
-		"f_stat: transcript path longer than MAXPATHLEN" );
-
-	    /* return constants */
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
-		    "f", av[ 2 ], 
-		    DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
-		    st.st_mtime, st.st_size, cksum_b64 );
-	    return( 0 );
-	}
-
-	/* if allowable, check for transcript in the special file directory */
-
-	strcat( path, ".T" );
-
-	/* store value of av[ 2 ], because argcargv will be called
+	/*
+	 * store value of av[ 2 ], because argcargv will be called
 	 * from special_t(), and that will blow away the current values
-	 * for av[ 2 ]
-	 *
-	 * Could just use new argvargc API... XXX  Notice how we never free
-	 * env_file...
+	 * for av[ 2 ].
 	 */
-
 	if (( enc_file = strdup( av[ 2 ] )) == NULL ) {
 	    syslog( LOG_ERR, "f_stat: strdup: %s %m", av[ 2 ] );
 	    return( -1 );
 	}
 
 	if (( av = special_t( path, enc_file )) == NULL ) {
-	    if (( av = special_t( "transcript/special.T", enc_file ))
-		    == NULL ) {
-		snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
-			"f", enc_file, 
-			DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID, 
-			st.st_mtime, st.st_size, cksum_b64 );
-		free( enc_file );
-		return( 0 );
-	    }
+	    /* no special transcript match found, return defaults. */
+	    snet_writef( sn, RADMIND_STAT_FMT,
+		    "f", enc_file, 
+		    DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID, 
+		    st.st_mtime, st.st_size, cksum_b64 );
+	    free( enc_file );
+	    return( 0 );
 	}
-	snet_writef( sn, "%s %s %s %s %s %d %" PRIofft "d %s\r\n",
+	snet_writef( sn, RADMIND_STAT_FMT,
 		av[ 0 ], enc_file,
 		av[ 2 ], av[ 3 ], av[ 4 ],
 		st.st_mtime, st.st_size, cksum_b64 );
@@ -1261,8 +1285,7 @@
 	    continue;
 	}
 	if ( strcmp( av[ 0 ], "@include" ) == 0 ) {
-	    depth++;
-	    if ( depth > RADMIND_MAX_INCLUDE_DEPTH ) {
+	    if ( depth >= RADMIND_MAX_INCLUDE_DEPTH ) {
 		syslog( LOG_ERR, "%s: line %d: include %s exceeds max depth",
 			path_config, linenum, av[ 1 ] );
 		goto command_k_done;
@@ -1277,7 +1300,7 @@
 		    continue;
 		}
 	    }
-	    if ( command_k( av[ 1 ], depth ) != 0 ) {
+	    if ( command_k( av[ 1 ], depth + 1 ) != 0 ) {
 		continue;
 	    }
 
@@ -1325,7 +1348,8 @@
 
     /* If we get here, the host that connected is not in the config
        file. So screw him. */
-    syslog( LOG_ERR, "host not in config file: %s", remote_host );
+    syslog( LOG_ERR, "host %s not in config file %s",
+		remote_host, path_config );
 
 command_k_done:
     snet_close( sn );
