--- encoding.cpp.orig	Wed Jul 19 11:30:05 2006
+++ encoding.cpp	Wed Jul 19 11:30:28 2006
@@ -2,7 +2,9 @@
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
-#include "freetype/freetype.h"
+#include <unistd.h>                                                            
+#include <zlib.h>
+#include <ft2build.h>
 
 #include "ttmkfdir.h"
 #include "encoding.h"
@@ -32,9 +34,16 @@
     NextFile (FILE *f, char *name)
     {
 	char file_name [1024];
-	char command[1024];
+	char line_buf [1024];
+	char tmp_file_name[] = "/tmp/ttmkfdir_XXXXXX";
+	char inbuf[300000];
+	FILE *od;
+	gzFile fd;
+	int rvalue, tmpfd;
 
-	if (fscanf (f, "%*s %[^\n]\n", file_name) == 1) {
+	if (fgets (line_buf, sizeof(line_buf), f) != NULL) {
+
+	    sscanf (line_buf, "%*s %[^\n]\n", file_name);
 
 	    if (file_name[0] == '/') {
 		name[0] = 0;
@@ -44,9 +53,25 @@
 	
 	    strcat (name, file_name);
 
-	    sprintf (command, "exec %s < %s", (toupper(name[strlen (name) - 1]) == 'Z')
-		     ? "gzip -d" : "cat", name);
-	    return popen (command, "r");
+	    bzero(inbuf, sizeof(inbuf));
+
+	    fd = gzopen (name,"rb");
+	    rvalue = gzread (fd, inbuf, sizeof(inbuf));
+
+	    tmpfd = mkstemp (tmp_file_name);
+	    if (tmpfd == -1) {
+		return 0;
+	    }
+
+	    od = fdopen (tmpfd,"w");
+	    fputs (inbuf, od);
+	    fflush (od);
+	    fclose (od);
+
+	    od = fopen (tmp_file_name,"r");
+	    unlink (tmp_file_name);
+	    return od;
+
 	}
 
 	return 0;
@@ -75,7 +100,7 @@
 	yyrestart (input);
 	yylex (name, *this);
 
-	pclose (input);
+	fclose (input);
     }
 
     fclose (f);
@@ -97,7 +122,7 @@
 
     NumericMapping *m = new NumericMapping (size, b->mapdata.platform, b->mapdata.encoding);
 
-    for (int i = 0; i < size; i++)
+    for (unsigned int i = 0; i < size; i++)
 	(*m)[i] = b->mapdata.mappingtable[i];
 
     AddMapping (m);
