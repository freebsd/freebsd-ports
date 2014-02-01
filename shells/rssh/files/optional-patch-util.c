--- util.c.orig	2012-11-27 12:14:49.000000000 +1100
+++ util.c	2013-01-09 17:52:54.000000000 +1100
@@ -56,6 +56,7 @@
 #ifdef HAVE_LIBGEN_H
 #include <libgen.h>
 #endif /* HAVE_LIBGEN_H */
+#include <regex.h>
 
 /* LOCAL INCLUDES */
 #include "pathnames.h"
@@ -198,6 +199,73 @@
 
 
 /*
+ * rsync_e_okay() - take the command line passed to rssh and look for an -e
+ *		    option.  If one is found, make sure --server is provided
+ *		    and the option contains only the protocol information.
+ *		    Also check for and reject any --rsh option.	 Returns FALSE
+ *		    if the command line should not be allowed, TRUE if it is
+ *		    okay.
+ */
+static int rsync_e_okay( char **vec )
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
+	if ( vec && vec[0] && vec[1] && strcmp(vec[1], "--server") == 0 ){
+		server = TRUE;
+	}
+
+	/* Check the remaining options for -e or --rsh. */
+	if ( regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0 ){
+		return FALSE;
+	}
+	while (vec && *vec){
+		if ( strcmp(*vec, "--") == 0 ) break;
+		if ( strcmp(*vec, "--rsh") == 0
+		     || strncmp(*vec, "--rsh=", strlen("--rsh=")) == 0 ){
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
+	if ( e_found && !server ) return FALSE;
+	return TRUE;
+}
+
+
+/*
  * check_command_line() - take the command line passed to rssh, and verify
  *			  that the specified command is one the user is
  *			  allowed to run and validate the arguments.  Return the
@@ -230,14 +298,10 @@
 
 	if ( check_command(*cl, opts, PATH_RSYNC, RSSH_ALLOW_RSYNC) ){
 		/* filter -e option */
-		if ( opt_filter(cl, 'e') ) return NULL;
-		while (cl && *cl){
-			if ( strstr(*cl, "--rsh" ) ){
-				fprintf(stderr, "\ninsecure --rsh= not allowed.");
-				log_msg("insecure --rsh option in rsync command line!");
-				return NULL;
-			}
-			cl++;
+		if ( !rsync_e_okay(cl) ){
+			fprintf(stderr, "\ninsecure -e or --rsh option not allowed.");
+			log_msg("insecure -e or --rsh option in rsync command line!");
+			return NULL;
 		}
 		return PATH_RSYNC;
 	}
