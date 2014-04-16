Description: SpamAssassin support, sanity checks.
 Implement SpamAssassin support.
 Honor limits correctly.
 Wait for the correct child process - waitpid() instead of wait().
 Check for a couple more errors.
 Add a closedir() to fix a file descriptor leak.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>,
	Alex Dupre <ale@FreeBSD.org>
Last-Update: 2009-11-26

--- vpopmail.c.orig	2011-02-28 11:00:45.000000000 -0600
+++ vpopmail.c	2014-04-10 11:20:59.892641589 -0500
@@ -981,6 +981,7 @@ int vdelfiles(char *dir)
 
           /* print error message and return and error */
           fprintf (stderr, "Failed to delete directory %s", mydirent->d_name);
+	  closedir(mydir);
           return(-1);
         }
       }
@@ -1603,7 +1604,7 @@ while(( s[i]==' ')||(s[i]=='\t')) {
    i++;
    }
 
-k = strlen(s) - i - 1; 
+k = strlen(s) - i;
 
 if( i>0 ) {
    for( j=0; j<k; j++ )  {
@@ -1615,7 +1616,7 @@ if( i>0 ) {
 
 //  trim spaces and tabs from end
 i = strlen(s) - 1;
-while(( s[i] == ' ' ) || ( s[i] == '\t' )) {
+while(i >= 0 && ( s[i] == ' ' || s[i] == '\t' )) {
    i--;
    }
 
@@ -2387,7 +2388,12 @@ char *make_user_dir(char *username, char
  int call_dir;
  char domain_dir[MAX_BUFF];
  const char *dirnames[] = {"Maildir", "Maildir/new", "Maildir/cur", 
-	"Maildir/tmp"};
+	"Maildir/tmp",
+#ifdef SPAM_JUNKFOLDER
+	"Maildir/.Junk", "Maildir/.Junk/new", "Maildir/.Junk/cur",
+	"Maildir/.Junk/tmp",
+#endif
+	};
  int i;
 
   verrori = 0;
@@ -3154,6 +3160,13 @@ int vmake_maildir(char *domain, char *di
   if (mkdir("cur",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
   if (mkdir("new",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
   if (mkdir("tmp",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+#ifdef SPAM_JUNKFOLDER
+  if (mkdir(".Junk",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+  if (chdir(".Junk") == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+  if (mkdir("cur",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+  if (mkdir("new",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+  if (mkdir("tmp",VPOPMAIL_DIR_MODE) == -1) { fchdir(call_dir); close(call_dir); return(-1); }
+#endif
 
   /* set permissions on the user's dir */
   chdir(dir);
@@ -4220,12 +4233,20 @@ int call_onchange ( const char *cmd )
 	}
 	else if ( pid > 0 )
 	{
-		wait(&rv);
-		return(rv);
+		if (waitpid ( pid, &rv, 0 ) < 0 ||
+		    !WIFEXITED( rv ) || WEXITSTATUS( rv ) != 0 ) {
+			fprintf(stderr,
+			    "ONCHANGE script %s did not exit gracefully.\n",
+			    path);
+			return(rv);
+		}
+		return(0);
 	}
 
-	fprintf(stderr, "ONCHANGE script %s unable to fork.\n", path);
-	return(0);
+	rv = errno;
+	fprintf(stderr, "ONCHANGE script %s unable to fork: %s\n", path,
+	    strerror(rv));
+	return(rv);
 }
 #endif
 
