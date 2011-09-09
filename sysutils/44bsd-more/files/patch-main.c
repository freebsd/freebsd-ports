--- main.c.orig	2011-09-08 01:02:56.000000000 +0800
+++ main.c	2011-09-08 01:17:47.000000000 +0800
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
 
@@ -68,6 +68,10 @@ static const char rcsid[] =
 #include "less.h"
 #include "pathnames.h"
 
+static int str_read(void *, char *, size_t);
+void rcfiles();
+void readrc(FILE *);
+
 int	ispipe;
 char	*current_file, *previous_file, *current_name, *next_name;
 int	any_display;
@@ -214,6 +218,7 @@ edit(filename, force_open)
 /*
  * Edit the next file in the command line list.
  */
+void
 next_file(n)
 	int n;
 {
@@ -281,7 +286,7 @@ main(argc, argv)
 	 * Process command line arguments and MORE environment arguments.
 	 * Command line arguments override environment arguments.
 	 */
-	if (envargv[1] = getenv("MORE")) {
+	if ((envargv[1] = getenv("MORE"))) {
 		envargc = 2;
 		envargv[0] = "more";
 		envargv[2] = NULL;
@@ -403,14 +408,14 @@ quit()
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
@@ -480,6 +485,7 @@ use_builtin_defrc:
  * This really belongs in ncommand.c, but that file is already 33292 bytes
  * long.
  */
+void
 readrc(fd)
 	FILE *fd;
 {
@@ -489,7 +495,7 @@ readrc(fd)
 
 	buf = NULL;
 	strlenbuf = 0;
-	while (bufptr = fgetln(fd, &len)) {
+	while ((bufptr = fgetln(fd, &len))) {
 		if (!len)
 			continue;  /* ??? */
 		if (*bufptr == '#')
