Verifies the command line options for rysnc. This is an updated version that
tightens the argument checking and requires to run rsync in server mode.
Taken from Debian ("0007-Verify-rsync-command-options").
--- util.c.orig	2012-11-27 01:14:49 UTC
+++ util.c
@@ -56,6 +56,7 @@
 #ifdef HAVE_LIBGEN_H
 #include <libgen.h>
 #endif /* HAVE_LIBGEN_H */
+#include <regex.h>
 
 /* LOCAL INCLUDES */
 #include "pathnames.h"
@@ -198,6 +199,71 @@ bool check_command( char *cl, ShellOptions_t *opts, ch
 
 
 /*
+ * rsync_okay() - require --server on all rsh command lines, check that -e
+ *		  contains only protocol information, and reject any --rsh,
+ *		  --config, or --daemon option. Returns FALSE if the command
+ *		  line should not be allowed, TRUE if it is okay.
+ */
+static int rsync_okay( char **vec )
+{
+	regex_t	re;
+	int	server = FALSE;
+	int	e_found = FALSE;
+
+	/*
+	 * rsync will send -e, followed by either just "." (meaning no special
+	 * protocol) or "N.N" (meaning a pre-release protocol version),
+	 * followed by some number of alphabetic flags indicating various
+	 * supported options.  There may be other options between - and the e,
+	 * but -e will always be the last option in the string.	 A typical
+	 * option passed by the client is "-ltpre.iL".
+	 *
+	 * Note that if --server is given, this should never be parsed as a
+	 * shell, but we'll tightly verify it anyway, just in case.
+	 *
+	 * This regex matches the acceptable flags containing -e, so if it
+	 * does not match, the command line should be rejected.
+	 */
+	static const char pattern[]
+	    = "^-[a-df-zA-Z]*e[0-9]*\\.[0-9]*[a-zA-Z]*$";
+
+	/*
+	 * Only recognize --server if it's the first option.  rsync itself
+	 * always passes it that way, and if it's not the first argument, it
+	 * could be hidden from the server as an argument to some other
+	 * option.
+	 */
+	if ( !(vec && vec[0] && vec[1] && strcmp(vec[1], "--server") == 0) )
+		return FALSE;
+
+	/* Check the remaining options for -e or --rsh. */
+	if ( regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0 ){
+		return FALSE;
+	}
+	while (vec && *vec){
+		if ( strcmp(*vec, "--rsh") == 0
+		     || strcmp(*vec, "--daemon") == 0
+		     || strcmp(*vec, "--config") == 0
+		     || strncmp(*vec, "--rsh=", strlen("--rsh=")) == 0
+		     || strncmp(*vec, "--config=", strlen("--config=")) == 0 ){
+			regfree(&re);
+			return FALSE;
+		}
+		if ( strncmp(*vec, "--", 2) != 0 && opt_exist(*vec, 'e') ){
+			e_found = TRUE;
+			if ( regexec(&re, *vec, 0, NULL, 0) != 0 ){
+				regfree(&re);
+				return FALSE;
+			}
+		}
+		vec++;
+	}
+	regfree(&re);
+	return TRUE;
+}
+
+
+/*
  * check_command_line() - take the command line passed to rssh, and verify
  *			  that the specified command is one the user is
  *			  allowed to run and validate the arguments.  Return the
@@ -229,16 +295,27 @@ char *check_command_line( char **cl, ShellOptions_t *o
 	}
 
 	if ( check_command(*cl, opts, PATH_RSYNC, RSSH_ALLOW_RSYNC) ){
-		/* filter -e option */
-		if ( opt_filter(cl, 'e') ) return NULL;
-		while (cl && *cl){
-			if ( strstr(*cl, "--rsh" ) ){
-				fprintf(stderr, "\ninsecure --rsh= not allowed.");
-				log_msg("insecure --rsh option in rsync command line!");
-				return NULL;
-			}
-			cl++;
+		if ( !rsync_okay(cl) ){
+			fprintf(stderr, "\ninsecure rsync options not allowed.");
+			log_msg("insecure rsync options in rsync command line!");
+			return NULL;
 		}
+
+		/*
+		 * rsync is linked with popt, which recognizes a configuration
+		 * file ~/.popt that can, among other things, define aliases.
+		 * If someone can write to the home directory of the rssh
+		 * user, they can upload a ~/.popt file that contains
+		 * something like "rsync alias --server --rsh" and then
+		 * execute commands they upload.  popt does not try to read
+		 * its configuration file if HOME is not set, so unset HOME to
+		 * disable this behavior.
+		 */
+		if ( unsetenv("HOME") < 0 ){
+			log_msg("cannot unsetenv() HOME");
+			return NULL;
+		}
+
 		return PATH_RSYNC;
 	}
 	/* No match, return NULL */
