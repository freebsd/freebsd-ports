--- xgraph.c.orig	Tue Nov 23 04:29:38 1993
+++ xgraph.c	Mon Jun 28 00:44:15 1999
@@ -46,8 +46,6 @@
 #define BTNPAD		1
 #define BTNINTER	3
 
-#define MAX(a,b)	((a) > (b) ? (a) : (b))
-#define MIN(a,b)	((a) < (b) ? (a) : (b))
 #define ABS(x)		((x) < 0 ? -(x) : (x))
 #define ZERO_THRES	1.0E-07
 
@@ -266,6 +264,7 @@
 	if (!strm) {
 	    (void) fprintf(stderr, "Warning:  cannot open file `%s'\n",
 			   inFileNames[idx]);
+	    errs++;
 	} else {
 	    if ((maxitems = ReadData(strm, inFileNames[idx])) < 0) {
 		errs++;
@@ -1369,6 +1368,8 @@
 	    while (*line && (*line != '\n') && (*line != '"')) line++;
 	    if (*line) *line = '\0';
 	} else {
+	    /* treat comma's as white space */
+	    for (first=line; *first; ++first) if (*first == ',') *first = ' ';
 	    first = line;
 	    while (*line && !isspace(*line)) line++;
 	    if (*line) {
