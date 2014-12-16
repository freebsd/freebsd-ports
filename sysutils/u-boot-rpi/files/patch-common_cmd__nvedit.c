--- common/cmd_nvedit.c.orig	2012-11-28 01:28:06 UTC
+++ common/cmd_nvedit.c
@@ -966,6 +966,23 @@ sep_err:
 }
 #endif
 
+#if defined(CONFIG_CMD_ENV_EXISTS)
+static int do_env_exists(cmd_tbl_t *cmdtp, int flag, int argc,
+		       char * const argv[])
+{
+	ENTRY e, *ep;
+
+	if (argc < 2)
+		return CMD_RET_USAGE;
+
+	e.key = argv[1];
+	e.data = NULL;
+	hsearch_r(e, FIND, &ep, &env_htab);
+
+	return (ep == NULL) ? 1 : 0;
+}
+#endif
+
 /*
  * New command line interface: "env" command with subcommands
  */
@@ -995,6 +1012,9 @@ static cmd_tbl_t cmd_env_sub[] = {
 	U_BOOT_CMD_MKENT(save, 1, 0, do_env_save, "", ""),
 #endif
 	U_BOOT_CMD_MKENT(set, CONFIG_SYS_MAXARGS, 0, do_env_set, "", ""),
+#if defined(CONFIG_CMD_ENV_EXISTS)
+	U_BOOT_CMD_MKENT(exists, 2, 0, do_env_exists, "", ""),
+#endif
 };
 
 #if defined(CONFIG_NEEDS_MANUAL_RELOC)
@@ -1033,6 +1053,9 @@ static char env_help_text[] =
 #if defined(CONFIG_CMD_EDITENV)
 	"env edit name - edit environment variable\n"
 #endif
+#if defined(CONFIG_CMD_ENV_EXISTS)
+	"env exists name - tests for existence of variable\n"
+#endif
 #if defined(CONFIG_CMD_EXPORTENV)
 	"env export [-t | -b | -c] [-s size] addr [var ...] - export environment\n"
 #endif
