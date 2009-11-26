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

--- a/vpopmail.c
+++ b/vpopmail.c
@@ -945,6 +945,7 @@
 
           /* print error message and return and error */
           fprintf (stderr, "Failed to delete directory %s", mydirent->d_name);
+	  closedir(mydir);
           return(-1);
         }
       }
@@ -1563,7 +1564,7 @@
    i++;
    }
 
-k = strlen(s) - i - 1; 
+k = strlen(s) - i;
 
 if( i>0 ) {
    for( j=0; j<k; j++ )  {
@@ -1575,7 +1576,7 @@
 
 //  trim spaces and tabs from end
 i = strlen(s) - 1;
-while(( s[i] == ' ' ) || ( s[i] == '\t' )) {
+while(i >= 0 && ( s[i] == ' ' || s[i] == '\t' )) {
    i--;
    }
 
@@ -2348,7 +2349,12 @@
  char calling_dir[MAX_BUFF];
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
@@ -3114,6 +3120,13 @@
   if (mkdir("cur",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
   if (mkdir("new",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
   if (mkdir("tmp",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
+#ifdef SPAM_JUNKFOLDER
+  if (mkdir(".Junk",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
+  if (chdir(".Junk") == -1) { chdir(calling_dir); return(-1); }
+  if (mkdir("cur",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
+  if (mkdir("new",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
+  if (mkdir("tmp",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); return(-1); }
+#endif
 
   /* set permissions on the user's dir */
   chdir(dir);
@@ -4163,11 +4176,19 @@
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
