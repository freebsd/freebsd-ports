--- src/gp_unifs.c.orig	Tue Jun  5 15:31:44 2001
+++ src/gp_unifs.c	Sun Jul 15 22:57:50 2001
@@ -28,6 +27,8 @@
 #include "gsutil.h"		/* for string_match */
 #include "stat_.h"
 #include "dirent_.h"
+#include "unistd_.h"
+#include <stdlib.h>             /* for mkstemp/mktemp */
 #include <sys/param.h>		/* for MAXPATHLEN */
 
 /* Some systems (Interactive for example) don't define MAXPATHLEN,
@@ -57,22 +58,44 @@
 FILE *
 gp_open_scratch_file(const char *prefix, char fname[gp_file_name_sizeof],
 		     const char *mode)
-{				/* The -8 is for XXXXXX plus a possible final / and -. */
-    int len = gp_file_name_sizeof - strlen(prefix) - 8;
-
-    if (gp_gettmpdir(fname, &len) != 0)
+{	/* The -8 is for XXXXXX plus a possible final / and -. */
+    int prefix_length = strlen(prefix);
+    int len = gp_file_name_sizeof - prefix_length - 8;
+
+    if (gp_file_name_is_absolute(prefix, prefix_length))
+	*fname = 0;
+    else if (gp_gettmpdir(fname, &len) != 0)
 	strcpy(fname, "/tmp/");
     else {
 	if (strlen(fname) != 0 && fname[strlen(fname) - 1] != '/')
 	    strcat(fname, "/");
     }
+    if (strlen(fname) + prefix_length + 8 >= gp_file_name_sizeof)
+	return 0;		/* file name too long */
     strcat(fname, prefix);
     /* Prevent trailing X's in path from being converted by mktemp. */
     if (*fname != 0 && fname[strlen(fname) - 1] == 'X')
 	strcat(fname, "-");
     strcat(fname, "XXXXXX");
+
+#ifdef HAVE_MKSTEMP
+    {
+	    int file;
+	    FILE *fp;
+
+	    file = mkstemp(fname);
+	    if (file < -1)
+		    return NULL;
+	    fp = fdopen(file, mode);
+	    if (fp == NULL)
+		    close(file);
+		    
+	    return fp;
+    }
+#else
     mktemp(fname);
     return gp_fopentemp(fname, mode);
+#endif
 }
 
 /* Open a file with the given name, as a stream of uninterpreted bytes. */
