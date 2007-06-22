--- ./main.c.orig	2007-06-22 14:48:44.602177005 +0800
+++ ./main.c	2007-06-22 14:48:44.620758150 +0800
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
 
@@ -68,6 +68,8 @@
 #include "less.h"
 #include "pathnames.h"
 
+static int str_read(void *, char *, size_t);
+
 int	ispipe;
 char	*current_file, *previous_file, *current_name, *next_name;
 int	any_display;
@@ -410,7 +412,6 @@
 	char *c;
 	int readrc();
 	int savederrno;
-	static int str_read();
 
 	/* The default builtin rc file */
 	if ((c = getenv("HOME")) &&
