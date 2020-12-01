--- monitord.c.orig	2003-01-16 21:39:44 UTC
+++ monitord.c
@@ -30,6 +30,8 @@ ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
 #include "monitord.h"
 #include "config.h"
 
+static int HUP;
+
 int main (int argc, char *arga[]) {
 
 	int i, num, interval;
@@ -69,7 +71,7 @@ int main (int argc, char *arga[]) {
 	// init the *file[];
 	for ( i = 0; i < _MAXLINE; i++ ) {		
 		file[i] = (char *) malloc ( (size_t) sizeof(char) * _BUFSIZE );
-		bzero ( file[i], sizeof (file[i]) );
+		bzero ( file[i], sizeof (*file[i]) );
 	}
 
 //	file = (char **) calloc (1000, (size_t) sizeof(char) * _BUFSIZE );
@@ -85,8 +87,8 @@ int main (int argc, char *arga[]) {
 			setsid ();
 			break;
 		}
-		default: 
-		exit(1);
+		default: // The parent exits
+		exit(0);
 	}
 
 	/* Read the configuration file, saving it in *file[] and return the number of lines
@@ -119,7 +121,7 @@ int read_conf ( char ***file, char *filename ) {
 	char *buf;
 
         buf = (char *) malloc ( (size_t) _BUFSIZE ); // init & zero the buffer
-        bzero (buf, sizeof (buf) );
+        bzero (buf, sizeof (*buf) );
 
 	line_count = 0;
 
@@ -146,7 +148,7 @@ int read_conf ( char ***file, char *filename ) {
 			strncpy ( (char *) file[line_count], buf, _BUFSIZE );
 //			realloc ( & file[1], (size_t) sizeof(char) * _BUFSIZE * (line_count + 1) );
 			// zero out the buffer so we don't have it hold old garbage
-			bzero (buf, sizeof (buf));
+			bzero (buf, sizeof (*buf));
 
 			line_count++; // Advance the counter
 	
@@ -179,7 +181,7 @@ int loop ( char **file, char *filename, int max_proc, 
 	char value[_BUFSIZE / 6];	/* generic value from config file */
 	char email[_BUFSIZE / 6];	/* admin's email */
 	char eserver[_BUFSIZE / 6];	/* admin's email server */
-	char delay[max_proc];		/* array for tracking delay times for processes  */
+	signed char delay[max_proc];		/* array for tracking delay times for processes  */
 
 	char cmdline[_BUFSIZE];		/* entire process line from config file */
 	char tmppath[_BUFSIZE];		/* temporary copy of script_path */
@@ -197,11 +199,13 @@ int loop ( char **file, char *filename, int max_proc, 
 	buf = (char *) malloc ( (size_t) _BUFSIZE ); // init the all purpose buffer
 	buf2 = (char *) malloc ( (size_t) _BUFSIZE ); // init another all purpose buffer
 	token = (char *) malloc ( (size_t) _BUFSIZE ); // init the token buffer
-	bzero (buf, sizeof (buf) );
-	bzero (buf2, sizeof (buf) );
-	bzero (token, sizeof (token) );
+	bzero (buf, sizeof (*buf) );
+	bzero (buf2, sizeof (*buf) );
+	bzero (token, sizeof (*token) );
 
 	FOUND = 0;
+
+	memset(delay, 0, max_proc*sizeof(char));
 	
 	// Main loop
 	while(1) {
@@ -290,8 +294,8 @@ int loop ( char **file, char *filename, int max_proc, 
 
 			bzero (param, sizeof(param));
 			while ((token = strtok(NULL, " \t"))) {
-				strncat (param, " ", sizeof(param));
-				strncat (param, token, sizeof(param));
+				strncat (param, " ", sizeof(*param));
+				strncat (param, token, sizeof(*param));
 			}
 
 			/* Each line has a \n at the end which must be removed
@@ -355,18 +359,18 @@ int loop ( char **file, char *filename, int max_proc, 
 //					printf("Couldn't open %s\n", buf);
 				}
 				// Set the FOUND flag if the process we're checking for is found
-				if (!strncmp (buf, proc, sizeof(buf))) FOUND = TRUE;
+				if (!strncmp (buf, proc, MIN(strlen(buf),strlen(proc)))) FOUND = TRUE;
 			}
 			closedir (dirp);   // Close the /proc directory
 
 			// If the process wasn't found in the process listing then start it
-			if (!FOUND && options.isauto && !delay[i]) {
+			if (!FOUND && options.isauto && delay[i] < interval) {
 
 				/* Email admin that the service has died, if the "mail"
 				option has been set in the options */
 				if (options.alert) {
-					bzero (buf, sizeof(buf));
-					bzero (buf2, sizeof(buf2));
+					bzero (buf, sizeof(*buf));
+					bzero (buf2, sizeof(*buf2));
 					sprintf (buf, "[%s] Service \"%s\" has died\n", getdate(), proc);
 					sprintf (buf2, "(monitord) SYSTEM ALERT, \"%s\" has died\n", proc);
 					mail (email, eserver, buf2, buf);
@@ -405,7 +409,7 @@ int loop ( char **file, char *filename, int max_proc, 
 						/* Email the admin that the service has been
 						restarted if "mail" option is set */
 						if (options.alert) {
-							bzero (buf, sizeof(buf));
+							bzero (buf, sizeof(*buf));
 							sprintf (buf, "[%s] restarted \"%s\" using \"%s %s\"\n", getdate(), proc, script_path, param);
 							sprintf (buf2, "(monitord) \"%s\" restarted\n", proc);
 							mail (email, eserver, buf2, buf);
@@ -418,7 +422,7 @@ int loop ( char **file, char *filename, int max_proc, 
 						been able to be	restarted if "mail" option
 						is set */
 						if (options.alert) {
-							bzero (buf, sizeof(buf));
+							bzero (buf, sizeof(*buf));
 							sprintf (buf, "[%s] unable to restart \"%s\"\n", getdate(), proc);
 							sprintf (buf2, "(monitord) SYSTEM ALERT: \"%s\" unable to restart\n", proc);
 							mail (email, eserver, buf2, buf);
@@ -454,13 +458,13 @@ char *getdate () {
 
 	struct timeval *tp;
 	struct timezone *tzp;
-	const time_t *time;
+	time_t *time;
 	char *buf;
 
 	buf = (char *) malloc ( (size_t) _BUFSIZE ); // init the time buffer
 	tp = (struct timeval *) malloc ( (size_t) sizeof (struct timeval) ); // init the time buffer
 	tzp = (struct timezone *) malloc ( (size_t) sizeof (struct timezone) ); // init the timezone buffer
-	time = (const time_t *) malloc ( (size_t) sizeof (time_t) ); // init the timezone buffer
+	time = (time_t *) malloc ( (size_t) sizeof (time_t) ); // init the timezone buffer
 
 	/* Get time of day in seconds since Epoch */
 	gettimeofday (tp, tzp);
