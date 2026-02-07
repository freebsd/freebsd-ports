--- command.c.orig	2011-09-08 01:05:11.000000000 +0800
+++ command.c	2011-09-08 01:09:16.000000000 +0800
@@ -50,11 +50,13 @@ static const char rcsid[] =
 
 #include <sys/param.h>
 
+#include <stdio.h>
+#include <stdlib.h>
 #include <assert.h>
 #include <ctype.h>
 #include <stdarg.h>
-#include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "less.h"
 #include "pathnames.h"
@@ -77,6 +79,7 @@ extern int screen_trashed;	/* The screen
 static int cmd_col;		/* Current screen column when accepting input */
 
 static cmd_char(), cmd_erase(), getcc();
+void error(char *);
 
 
 /*****************************************************************************
@@ -448,6 +451,7 @@ SETERRSTR(enum error e, const char *s, .
 /*
  * Prints an error message and clears the current error.
  */
+void
 handle_error()
 {
 	if (erreur == E_OK)
@@ -465,6 +469,7 @@ handle_error()
 /*
  * Clears any error messages and pretends they never occurred.
  */
+void
 clear_error()
 {
 	erreur = E_OK;
@@ -480,6 +485,7 @@ static char return_to_continue[] = "(pre
  * and wait for carriage return.
  */
 /* static */
+void
 error(s)
 	char *s;
 {
@@ -553,6 +559,7 @@ error(s)
  *
  * Accept and execute commands until a quit command, then return.
  */
+void
 commands()
 {
 	enum runmacro runmacro();
@@ -646,6 +653,7 @@ commands()
  * 
  */
 
+void
 editfile()
 {
 	off_t position();
@@ -707,6 +715,7 @@ editfile()
 	lsystem(buf);
 }
 
+void
 showlist()
 {
 	extern int sc_width;
