--- main.c.orig	2020-10-02 14:29:21 UTC
+++ main.c
@@ -38,6 +38,17 @@
 /* Header files */
 #include "ibsh.h"
 
+theuser loggedin; /* user info */
+
+Strng commands[MAX_ITEMS];    /* permitted commands */
+Strng extensions[MAX_ITEMS];  /* permitted extensions */
+char real_path[STRING_SIZE];  /* absolute path */
+char jail_path[STRING_SIZE];  /* path inside the jail */
+char user_command[STRING_SIZE];     /* whatever the user types */
+char filtered_command[STRING_SIZE]; /* this one will be executed */
+int exitcode;
+
+
 /* Main: */
 /* Handle arguments, read config files, start command processing. */
 /* IBSH doesnt use any command line arguments, but my text editor */
