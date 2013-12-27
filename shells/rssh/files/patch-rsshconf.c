--- ./rsshconf.c.orig	2012-11-27 01:33:27.000000000 +0100
+++ ./rsshconf.c	2013-12-27 09:57:15.000000000 +0100
@@ -78,7 +78,7 @@
 	NULL
 };
 
-int log=0;
+int rsshlog=0;
 
 /* flag to tell config parser to stop processing config file */
 static bool got_user_config = FALSE;
@@ -132,11 +132,11 @@
 	int 	status = TRUE;		/* were all the cfg lines good? */
         char 	line[CFG_LINE_LEN + 1];	/* buffer to hold region */
 
-	log = do_log;
+	rsshlog = do_log;
 	memset(line, 0, CFG_LINE_LEN + 1);
         cfg_file = fopen(filename, "r");
         if (!cfg_file) {
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_WARNING);
 			log_msg("config file (%s) missing, using defaults", 
 				filename);
@@ -174,7 +174,7 @@
 		*newline = '\0';
 	else {
 		/* there is no newline - log the error and find the EOL */
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("line %d: line too long", lineno);
 		}
@@ -241,12 +241,12 @@
 		return TRUE;
 	default:
 		/* the keyword is unknown */
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("line %d: syntax error parsing config file",
 				       	lineno);
 		}
-		if ( keywrd[0] && log )
+		if ( keywrd[0] && rsshlog )
 			log_msg("unknown keyword: %s", keywrd);
 		return FALSE;
 	}
@@ -330,7 +330,7 @@
 	/* initialize strings and pointers */
 	memset(buf, 0, buflen);
 	if ( !(copy = strdup(str)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("OOM error in get_token() (fatal)");
 		}
@@ -433,11 +433,11 @@
 		       const int lineno )
 {
 	if ( !eat_comment(line) ){
-		if (log) log_msg("line %d: syntax error parsing config file",
+		if (rsshlog) log_msg("line %d: syntax error parsing config file",
 				       	lineno);
 		return FALSE;
 	}
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing scp to all users");
 	}
@@ -460,11 +460,11 @@
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (rsshlog) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing sftp to all users");
 	}
@@ -488,11 +488,11 @@
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (rsshlog) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing cvs to all users");
 	}
@@ -516,12 +516,12 @@
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (rsshlog) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
 	log_set_priority(LOG_INFO);
-	if (log){
+	if (rsshlog){
 		log_msg("allowing rdist to all users");
 		opts->shell_flags |= RSSH_ALLOW_RDIST;
 	}
@@ -544,11 +544,11 @@
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (rsshlog) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing rsync to all users");
 	}
@@ -573,7 +573,7 @@
 	 */
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for chroot path");
+		if (rsshlog) log_msg("fatal error: can't allocate space for chroot path");
 		exit(1);
 	}
 	/* get_asgn_param() eats trailing comments, so we won't */
@@ -584,7 +584,7 @@
 	
 	/* get rid of any old value for chroot path, assign new one */
 	if ( opts->chroot_path ) free(opts->chroot_path);
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("chrooting all users to %s", temp);
 	}
@@ -605,7 +605,7 @@
 	int	pos;
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("fatal error: can't allocate space for log facility");
 		}
@@ -778,17 +778,17 @@
 
 	free(temp);
 	if ( !eat_comment(line + pos) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (rsshlog) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
 	if ( facname ){
 		log_set_priority(LOG_INFO);
-		if (log) log_msg("setting log facility to %s", facname);
+		if (rsshlog) log_msg("setting log facility to %s", facname);
 		log_set_facility(fac);
 		return TRUE;
 	}
-	if (log){
+	if (rsshlog){
 		log_msg("line %d: unknown log facility specified", lineno);
 		log_set_facility(LOG_USER);
 	}
@@ -804,7 +804,7 @@
 	int	mask;		/* umask */
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("fatal error: can't allocate space in process_umask()");
 		}
@@ -818,7 +818,7 @@
 
 	/* convert the umask to a number */
 	if ( !validate_umask(temp, &mask) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_WARNING);
 			log_msg("line %d: invalid umask specified, using default 077",
 			lineno);
@@ -827,7 +827,7 @@
 		free(temp);
 		return FALSE;
 	}
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("setting umask to %#o", mask);
 	}
@@ -857,7 +857,7 @@
 
 	/* make space for user options */
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for user options");
+		if (rsshlog) log_msg("fatal error: can't allocate space for user options");
 		exit(1);
 	}
 
@@ -870,7 +870,7 @@
 
 	/* now process individual config bits of temp */
 	if ( !(pos = get_token(temp, user, CFG_LINE_LEN + 1, TRUE, TRUE )) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file, line %d", 
 					lineno);
@@ -887,12 +887,12 @@
 	 * user lines we don't care about...
 	 */
 	if ( (strcmp(user, username)) ) return TRUE;
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("line %d: configuring user %s", lineno, user);
 	}
 	if ( !(len = eat_colon(temp + pos)) ){
-		if (log) log_msg("syntax error parsing config file: line %d ", 
+		if (rsshlog) log_msg("syntax error parsing config file: line %d ", 
 				lineno);
 		return FALSE;
 	}
@@ -901,7 +901,7 @@
 	/* do the umask, but validate it last, since it's non-fatal */
 	if ( !(len = get_token(temp + pos, mask, CFG_LINE_LEN + 1, 
 			       TRUE, FALSE)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user umask, line %d", lineno);
 		}
@@ -911,14 +911,14 @@
 
 	/* do the access bits */
 	if ( !(len = eat_colon(temp + pos)) ){
-		if (log) log_msg("syntax error parsing config file: line %d ", 
+		if (rsshlog) log_msg("syntax error parsing config file: line %d ", 
 				lineno);
 		return FALSE;
 	}
 	pos += len;
 	if ( !(len = get_token(temp + pos, axs, CFG_LINE_LEN + 1, 
 			       TRUE, FALSE)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user access, line %d", lineno);
 		}
@@ -926,7 +926,7 @@
 	}
 	if ( !validate_access(axs, &allow_sftp, &allow_scp, &allow_cvs,
 			      &allow_rdist, &allow_rsync) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing access bits, line %d", lineno);
 		}
@@ -938,7 +938,7 @@
 	if ( !(len = eat_colon(temp + pos)) ) goto cleanup;
 	pos += len;
 	if ( !(path = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for chroot path");
+		if (rsshlog) log_msg("fatal error: can't allocate space for chroot path");
 		exit(1);
 	}
 	if ( !(len = get_token(temp + pos, path, CFG_LINE_LEN + 1, 
@@ -952,7 +952,7 @@
 	/* make sure nothing is left */
 	while ( *(temp + pos) != '\0' && isspace(*(temp + pos)) ) pos++;
 	if ( *(temp + pos) != '\0' ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user config: line %d", lineno);
 		}
@@ -961,14 +961,14 @@
 
 	/* now finally validate the umask */
 	if ( !validate_umask(mask, &tmpmask) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_WARNING);
 			log_msg("line %d: invalid umask specified, using default",
 			lineno);
 		}
 		tmpmask = 077;
 	} 
-	if (log){
+	if (rsshlog){
 		log_set_priority(LOG_INFO);
 		log_msg("setting %s's umask to %#o", user, tmpmask);
 	}
@@ -980,27 +980,27 @@
 	opts->shell_flags = 0;
 	/* now set the user-specific flags */
 	if ( allow_scp ){
-		if (log) log_msg("allowing scp to user %s", user);
+		if (rsshlog) log_msg("allowing scp to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_SCP;
 	}
 	if ( allow_sftp ){
-		if (log) log_msg("allowing sftp to user %s", user);
+		if (rsshlog) log_msg("allowing sftp to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_SFTP;
 	}
 	if ( allow_cvs ){
-		if (log) log_msg("allowing cvs to user %s", user);
+		if (rsshlog) log_msg("allowing cvs to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_CVS;
 	}
 	if ( allow_rdist ){
-		if (log) log_msg("allowing rdist to user %s", user);
+		if (rsshlog) log_msg("allowing rdist to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_RDIST;
 	}
 	if ( allow_rsync ){
-		if (log) log_msg("allowing rsync to user %s", user);
+		if (rsshlog) log_msg("allowing rsync to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_RSYNC;
 	}
 	if ( path ){
-		if (log) log_msg("chrooting %s to %s", user, path);
+		if (rsshlog) log_msg("chrooting %s to %s", user, path);
 		opts->shell_flags |= RSSH_USE_CHROOT;
 	}
 	opts->chroot_path = path;
@@ -1019,7 +1019,7 @@
 
 	/* make sure '=' is next token, otherwise syntax error */
 	if ( (pos = eat_assignment(line)) <= 0 ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("error parsing config file at line %d: "
 			"assignment expected", lineno);
@@ -1028,7 +1028,7 @@
 	}
 	/* get the string parameter of the assignment */
 	if ( !(len = get_token((line + pos), buf, buflen, FALSE, FALSE)) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file, line %d", 
 				lineno);
@@ -1038,7 +1038,7 @@
 	pos += len;
 	/* check for ending comment */
 	if ( !eat_comment(line + pos) ){
-		if (log){
+		if (rsshlog){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file at line %d", 
 				lineno);
