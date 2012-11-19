Index: src/console_cli.c
===================================================================
--- src/console_cli.c	(revision 3997)
+++ src/console_cli.c	(working copy)
@@ -24,10 +24,10 @@
 
 #define MODE_CONFIG_NUGGET 10
 #define MODE_CONFIG_APP_TYPE 11
-#define DECL_COMMAND(x) static int x(struct cli_def *cli, char *command, char *argv[], int argc)
+#define DECL_COMMAND(x) static int x(struct cli_def *cli, const char *command, char **argv, int argc)
 
 int
-check_auth (char *username, char *password)
+check_auth (const char *username, const char *password)
 {
     // TODO: Add support for other auth backends
     if (strcasecmp (username, g_sConsoleUser) != 0)
@@ -38,7 +38,7 @@
 }
 
 int
-check_enable (char *password)
+check_enable (const char *password)
 {
     // TODO: Add support for other auth backends
     return !strcasecmp (password, g_sConsoleEnablePassword);
