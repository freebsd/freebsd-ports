--- src/readln.h.orig	2023-04-17 14:45:07 UTC
+++ src/readln.h
@@ -29,7 +29,7 @@ typedef struct {
   char *doc;			/* Documentation for this function.  */
 } COMMAND;
 
-COMMAND *thecommandlist;
+extern COMMAND *thecommandlist;
 
 COMMAND *find_command(char *name, COMMAND *commands);
 int execute_line (char *line, COMMAND *commands);
