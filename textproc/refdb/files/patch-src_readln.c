--- src/readln.c.orig	2023-04-17 14:45:25 UTC
+++ src/readln.c
@@ -27,6 +27,7 @@
 #include "strfncs.h"
 
 extern COMMAND commands[];
+COMMAND *thecommandlist;
 
 /* Execute a command line. */
 int execute_line (char *line, COMMAND *commandlist)
