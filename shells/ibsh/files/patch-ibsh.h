--- ibsh.h.orig	2020-10-02 14:29:21 UTC
+++ ibsh.h
@@ -88,17 +88,15 @@ typedef struct theuser {
 
 typedef char Strng[STRING_SIZE];
 
-theuser loggedin; /* user info */
+extern theuser loggedin; /* user info */
 
-//static Strng commands[MAX_ITEMS];  /* permitted commands */
-Strng commands[MAX_ITEMS];
-Strng extensions[MAX_ITEMS];
-/*static Strng extensions[MAX_ITEMS];   permitted extensions */
-char real_path[STRING_SIZE];    /* absolute path */
-char jail_path[STRING_SIZE];    /* path inside the jail */
-char user_command[STRING_SIZE];   /* whatever the user types */
-char filtered_command[STRING_SIZE]; /* this one will be executed */
-int exitcode;
+extern Strng commands[MAX_ITEMS];    /* permitted commands */
+extern Strng extensions[MAX_ITEMS];  /* permitted extensions */
+extern char real_path[STRING_SIZE];  /* absolute path */
+extern char jail_path[STRING_SIZE];  /* path inside the jail */
+extern char user_command[STRING_SIZE];     /* whatever the user types */
+extern char filtered_command[STRING_SIZE]; /* this one will be executed */
+extern int exitcode;
 extern char **environ;
 
 
