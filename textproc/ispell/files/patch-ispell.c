--- ispell.c.orig	Wed Jul 25 17:51:46 2001
+++ ispell.c	Sat Feb 22 14:24:29 2003
@@ -209,6 +209,7 @@
 #include <fcntl.h>
 #endif /* NO_FCNTL_H */
 #include <sys/stat.h>
+#include <libgen.h>
 
 static void	usage P ((void));
 static void	initckch P ((char * wchars));
@@ -327,6 +328,7 @@
     char **	versionp;
     char *	wchars = NULL;
     char *	preftype = NULL;
+    char * 	cmdname;
     static char	libdictname[sizeof DEFHASH];
     static char	outbuf[BUFSIZ];
     int		argno;
@@ -334,6 +336,11 @@
 
     Cmd = *argv;
 
+    cmdname = (char *)basename(argv[0]);
+    if (strncmp(cmdname, "spell", 5) == 0) {
+	uflag++;
+    }
+
     Trynum = 0;
 
     p = getenv ("DICTIONARY");
@@ -792,6 +799,11 @@
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
@@ -827,7 +839,7 @@
 	argc--;
 	}
 
-    if (!argc  &&  !lflag  &&  !aflag   &&  !eflag  &&  !dumpflag)
+    if (!argc  &&  !lflag  &&  !aflag   &&  !eflag  &&  !dumpflag  &&  !uflag)
 	{
 	if (argc != 0)
 	    usage ();
@@ -848,7 +860,7 @@
 	if (access (argv[argno], 4) >= 0)
 	    break;
 	}
-    if (argno >= argc  &&  !lflag  &&  !aflag  &&  !eflag  &&  !dumpflag)
+    if (argno >= argc  &&  !lflag  &&  !aflag  &&  !eflag  &&  !dumpflag  && !uflag)
 	{
 	(void) fprintf (stderr,
 	  argc == 1 ? ISPELL_C_NO_FILE : ISPELL_C_NO_FILES);
@@ -935,6 +947,29 @@
 	outfile = stdout;
 	checkfile ();
 	exit (0);
+	}
+
+    if (uflag)
+	{
+	lflag++;
+	if (!argc)
+	    {
+	    infile = setupdefmt(NULL);
+	    outfile = stdout;
+	    checkfile ();
+	    exit (0);
+	    }
+	else
+	    {
+    	    while (argc--)
+		{
+	        infile = setupdefmt (*argv++);
+	        outfile = stdout;
+		checkfile ();
+    		(void) fclose (infile);
+		}
+	    exit (0);
+	    }
 	}
 
     terminit ();
