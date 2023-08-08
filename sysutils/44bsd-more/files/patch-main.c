--- main.c.orig	2023-06-25 13:45:14.613216000 -0700
+++ main.c	2023-06-25 13:49:15.978996000 -0700
@@ -33,9 +33,9 @@
  */
 
 #ifndef lint
-char copyright[] =
+char copyright[] = \
 "@(#) Copyright (c) 1988 Mark Nudleman.\n\
-@(#) Copyright (c) 1988, 1993
+@(#) Copyright (c) 1988, 1993\
 	Regents of the University of California.  All rights reserved.\n";
 #endif /* not lint */
 
@@ -68,6 +68,10 @@
 #include "less.h"
 #include "pathnames.h"
 
+static int str_read(void *, char *, int);
+void rcfiles();
+void readrc(FILE *);
+
 int	ispipe;
 char	*current_file, *previous_file, *current_name, *next_name;
 int	any_display;
@@ -214,6 +218,7 @@
 /*
  * Edit the next file in the command line list.
  */
+void
 next_file(n)
 	int n;
 {
@@ -281,7 +286,7 @@
 	 * Process command line arguments and MORE environment arguments.
 	 * Command line arguments override environment arguments.
 	 */
-	if (envargv[1] = getenv("MORE")) {
+	if ((envargv[1] = getenv("MORE"))) {
 		envargc = 2;
 		envargv[0] = "more";
 		envargv[2] = NULL;
@@ -403,14 +408,14 @@
  * Read in from each of the three rc files - default, system, user.
  * Calls handle_error() directly to report errors.
  */
+void
 rcfiles()
 {
 	FILE *fd;
 	char fbuf[MAXPATHLEN + 1];
 	char *c;
-	int readrc();
+	// int readrc();
 	int savederrno;
-	static int str_read();
 
 	/* The default builtin rc file */
 	if ((c = getenv("HOME")) &&
@@ -480,6 +485,7 @@
  * This really belongs in ncommand.c, but that file is already 33292 bytes
  * long.
  */
+void
 readrc(fd)
 	FILE *fd;
 {
@@ -489,7 +495,7 @@
 
 	buf = NULL;
 	strlenbuf = 0;
-	while (bufptr = fgetln(fd, &len)) {
+	while ((bufptr = fgetln(fd, &len))) {
 		if (!len)
 			continue;  /* ??? */
 		if (*bufptr == '#')
@@ -527,7 +533,7 @@
 str_read(cookie, buf, len)
 	void *cookie;
 	char *buf;
-	size_t len;
+	int len;
 {
 	static char *curpos;
 	static int cooklen;
