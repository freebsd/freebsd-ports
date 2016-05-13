--- rundiff.c.orig	1994-05-19 02:01:22 UTC
+++ rundiff.c
@@ -63,7 +63,7 @@ typedef enum { ADD = 1, CHANGE, DELETE, 
 static char *duplicate (char *s, int *flag);
 static DiffType parse_diff_line (char *buf, int *f1n1, int *f1n2, int *f2n1, int *f2n2);
 static int eatline (FILE *f);
-static void getline (FILE *f, char **cooked, char **raw);
+static void get_line (FILE *f, char **cooked, char **raw);
 static void reset_blist (void);
 static Block *get_blist (void);
 static void add_blist (Block *b);
@@ -271,7 +271,7 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -300,7 +300,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[RIGHT].wtext = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
 	    b->arr[RIGHT].tlen = (short *) calloc (b->arr[RIGHT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[RIGHT].fsize; i++) {
-		getline (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
+		get_line (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
 		b->arr[RIGHT].tlen[i] = strlen (b->arr[RIGHT].text[i]);
 		if (di->maxcols < b->arr[RIGHT].tlen[i]) {
 		    di->maxcols = b->arr[RIGHT].tlen[i];
@@ -331,7 +331,7 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -358,7 +358,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 	    b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		    di->maxcols = b->arr[LEFT].tlen[i];
@@ -371,7 +371,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[RIGHT].wtext = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
 	    b->arr[RIGHT].tlen = (short *) calloc (b->arr[RIGHT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[RIGHT].fsize; i++) {
-		getline (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
+		get_line (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
 		b->arr[RIGHT].tlen[i] = strlen (b->arr[RIGHT].text[i]);
 		if (di->maxcols < b->arr[RIGHT].tlen[i]) {
 		    di->maxcols = b->arr[RIGHT].tlen[i];
@@ -399,7 +399,7 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -428,7 +428,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 	    b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		    di->maxcols = b->arr[LEFT].tlen[i];
@@ -491,7 +491,7 @@ DiffInfo *build_diff_info (char *prog, c
 	b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
 	b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
  	for (i = 0; i < b->arr[LEFT].fsize; i++) {
-	    getline (file2, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+	    get_line (file2, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 	    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 	    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		di->maxcols = b->arr[LEFT].tlen[i];
@@ -663,7 +663,7 @@ static int eatline (FILE *f)
  * printable) if necessary.  Silently truncate input lines at BUFSIZ
  * characters.
  */
-static void getline (FILE *f, char **cooked, char **raw)
+static void get_line (FILE *f, char **cooked, char **raw)
 {
     char buffer[BUFSIZ+1];
     char *s;
