--- print_cmd.c.orig	Fri Aug 29 12:06:43 2003
+++ print_cmd.c	Fri Aug 29 12:07:51 2003
@@ -20,7 +20,7 @@
 #include <stdio.h>
 
 #if defined (HAVE_VARARGS_H)
-#  include <varargs.h>
+#  include <stdarg.h>
 #endif
 
 #if defined (HAVE_STRING_H)
@@ -41,7 +41,8 @@
 static int indentation = 0;
 static int indentation_amount = 4;
 
-static void cprintf (), newline (), indent (), the_printed_command_resize ();
+static void cprintf (char *, ...);
+static void newline (), indent (), the_printed_command_resize ();
 static void semicolon ();
 
 static void make_command_string_internal ();
@@ -730,16 +731,14 @@
 
 /* How to make the string. */
 static void
-cprintf (va_alist)
-     va_dcl
+cprintf (char *control, ...)
 {
   register char *s;
-  char *control, char_arg[2], *argp;
+  char char_arg[2], *argp;
   int digit_arg, arg_len, c;
   va_list args;
 
-  va_start (args);
-  control = va_arg (args, char *);
+  va_start (args, control);
 
   arg_len = strlen (control);
   the_printed_command_resize (arg_len + 1);
