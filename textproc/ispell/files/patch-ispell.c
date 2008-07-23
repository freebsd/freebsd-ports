--- ispell.c.orig	2005-05-25 09:13:53.000000000 -0500
+++ ispell.c	2008-07-04 12:12:02.000000000 -0500
@@ -235,6 +235,7 @@
 #include <fcntl.h>
 #endif /* NO_FCNTL_H */
 #include <sys/stat.h>
+#include <libgen.h>
 
 static void	usage P ((void));
 int		main P ((int argc, char * argv[]));
@@ -272,6 +273,7 @@
     char **	versionp;
     char *	wchars = NULL;
     char *	preftype = NULL;
+    char * 	cmdname;
     static char	libdictname[sizeof DEFHASH];
     char	logfilename[MAXPATHLEN];
     static char	outbuf[BUFSIZ];
@@ -280,6 +282,11 @@
 
     Cmd = *argv;
 
+    cmdname = (char *)basename(argv[0]);
+    if (strncmp(cmdname, "spell", 5) == 0) {
+	uflag++;
+    }
+
     Trynum = 0;
 
     p = getenv (LIBRARYVAR);
@@ -851,6 +858,11 @@
 			LibDict = p + 1;
 		    }
 		break;
+	    case 'u':
+		if (arglen > 2)
+		    usage ();
+		uflag++;
+		break;
 	    case 'V':		/* Display 8-bit characters as M-xxx */
 		if (arglen > 2)
 		    usage ();
@@ -886,7 +898,7 @@
 	argc--;
 	}
 
-    if (!argc  &&  !lflag  &&  !aflag   &&  !eflag  &&  !dumpflag)
+    if (!argc  &&  !lflag  &&  !aflag   &&  !eflag  &&  !dumpflag  &&  !uflag)
 	{
 	if (argc != 0)
 	    usage ();
@@ -907,7 +919,7 @@
 	if (access (argv[argno], R_OK) >= 0)
 	    break;
 	}
-    if (argno >= argc  &&  !lflag  &&  !aflag  &&  !eflag  &&  !dumpflag)
+    if (argno >= argc  &&  !lflag  &&  !aflag  &&  !eflag  &&  !dumpflag  && !uflag)
 	{
 	(void) fprintf (stderr,
 	  argc == 1 ? ISPELL_C_NO_FILE : ISPELL_C_NO_FILES);
@@ -988,9 +1000,9 @@
 	exit (0);
 	}
 
-#ifndef __bsdi__
+#ifndef BSD4_4
     setbuf (stdout, outbuf);
-#endif /* __bsdi__ */
+#endif /* BSD4_4 */
     if (lflag)
 	{
 	infile = setupdefmt(NULL, NULL);
@@ -999,6 +1011,35 @@
 	exit (0);
 	}
 
+    if (uflag)
+	{
+	lflag++;
+	if (!argc)
+	    {
+	    infile = setupdefmt(NULL, NULL);
+	    outfile = stdout;
+	    checkfile ();
+	    exit (0);
+	    }
+	else
+	    {
+    	    while (argc--)
+		{
+    		if ((infile = setupdefmt (*argv, NULL)) == NULL)
+		{
+			(void) fprintf (stderr, CANT_OPEN, *argv);
+			(void) sleep ((unsigned) 2);
+		} else {
+	        	outfile = stdout;
+			checkfile ();
+    			(void) fclose (infile);
+		}
+		argv++;
+		}
+	    exit (0);
+	    }
+	}
+
     /*
      * If there is a log directory, open a log file.  If the open
      * fails, we just won't log.
