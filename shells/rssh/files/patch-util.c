Workaround for basename(3) that is POSIX compliant since r308264 in FreeBSD 12

Fixes buffer allocation for the fail message. Taken from Debian
("0003-Fix-buffer-allocation-buffer-for-fail-message").

Tightens the check for scp command line arguments that fixes also
"CVE-2019-1000018". Taken from Debian ("0009-Verify-scp-command-options").
Please note that with this patch the scp option "-3" can no longer be used.

--- util.c.orig	2012-11-27 01:14:49 UTC
+++ util.c
@@ -84,7 +84,7 @@ void fail( int flags, int argc, char **argv )
 	/* create msg indicating what is allowed */
 	if ( !size ) cmd = "This user is locked out.";
 	else {
-		size += 18;
+		size += 18 + 1;
 		if ( !(cmd = (char *)malloc(size)) ){
 			log_msg("fatal error: out of mem allocating log msg");
 			exit(1);
@@ -165,6 +165,7 @@ bool check_command( char *cl, ShellOptions_t *opts, ch
 {
 	char	*prog;		/* basename of cmd */
 	char 	*tmp = cl;
+	char    *tmp2 = NULL;
 	bool	need_free = FALSE;
 	bool	rc = FALSE;
 	int 	i;
@@ -186,11 +187,17 @@ bool check_command( char *cl, ShellOptions_t *opts, ch
 		}
 
 		/* compare tmp to cmd and prog for match */
-		prog = basename(cmd);
+		tmp2 = strdup (cmd);
+		if (tmp2 == NULL) {
+			log_msg ("strdup() failed in check_command()");
+			return FALSE;
+		}
+		prog = basename(tmp2);
 		if ( !(strcmp(tmp, cmd)) || !(strcmp(tmp, prog))){
 			log_msg("cmd '%s' approved", prog);
 			rc = TRUE;
 		}	
+		free (tmp2);
 	}
 	if (need_free) free(tmp);
 	return rc;
@@ -198,6 +205,43 @@ bool check_command( char *cl, ShellOptions_t *opts, ch
 
 
 /*
+ * scp_okay() - take the command line and check that it is a hopefully-safe scp
+ *		server command line, accepting only very specific options.
+ *		Returns FALSE if the command line should not be allowed, TRUE
+ *		if it is okay.
+ */
+static int scp_okay( char **vec )
+{
+	int saw_f_or_t = FALSE;
+
+	for ( vec++; vec && *vec; vec++ ){
+		/* Allowed options. */
+		if ( strcmp(*vec, "-v") == 0 ) continue;
+		if ( strcmp(*vec, "-r") == 0 ) continue;
+		if ( strcmp(*vec, "-p") == 0 ) continue;
+		if ( strcmp(*vec, "-d") == 0 ) continue;
+		if ( strcmp(*vec, "-f") == 0 || strcmp(*vec, "-pf") == 0 ){
+			saw_f_or_t = TRUE;
+			continue;
+		}
+		if ( strcmp(*vec, "-t") == 0 || strcmp(*vec, "-pt") == 0 ){
+			saw_f_or_t = TRUE;
+			continue;
+		}
+
+		/* End of arguments. */
+		if ( strcmp(*vec, "--") == 0 ) break;
+
+		/* Any other argument is not allowed. */
+		if ( *vec[0] == '-' ) return FALSE;
+	}
+
+	/* Either -f or -t must have been given. */
+	return saw_f_or_t;
+}
+
+
+/*
  * check_command_line() - take the command line passed to rssh, and verify
  *			  that the specified command is one the user is
  *			  allowed to run and validate the arguments.  Return the
@@ -212,8 +256,11 @@ char *check_command_line( char **cl, ShellOptions_t *o
 		return PATH_SFTP_SERVER;
 
 	if ( check_command(*cl, opts, PATH_SCP, RSSH_ALLOW_SCP) ){
-		/* filter -S option */
-		if ( opt_filter(cl, 'S') ) return NULL;
+		if ( !scp_okay(cl) ){
+			fprintf(stderr, "\ninsecure scp option not allowed.");
+			log_msg("insecure scp option in scp command line");
+			return NULL;
+		}
 		return PATH_SCP;
 	}
 
