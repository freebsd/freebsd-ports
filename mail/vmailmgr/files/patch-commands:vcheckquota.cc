--- commands/vcheckquota.cc.orig	Mon Feb  2 15:00:41 2004
+++ commands/vcheckquota.cc	Mon Feb  2 15:01:15 2004
@@ -31,10 +31,10 @@
 
 const char* cli_program = "vcheckquota";
 const char* cli_help_prefix = "vmailmgr quota enforcement program\n";
-const char* cli_help_suffix = "
-Warning: the soft-message is linked into the users maildir once for each
-message that is received while the account is over its soft quota.  This may
-result in multiple warning messages.\n";
+const char* cli_help_suffix = "\n"
+"Warning: the soft-message is linked into the users maildir once for each\n"
+"message that is received while the account is over its soft quota.  This may\n"
+"result in multiple warning messages.\n";
 const char* cli_args_usage = "";
 const int cli_args_min = 0;
 const int cli_args_max = 0;
