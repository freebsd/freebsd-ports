--- commands/vpasswd2db.cc.orig	Mon Feb  2 15:02:15 2004
+++ commands/vpasswd2db.cc	Mon Feb  2 15:02:33 2004
@@ -26,9 +26,9 @@
 const char* cli_program = "vpasswd2db";
 const char* cli_help_prefix = "Converts text password tables to current vpwtable DB format\n";
 const char* cli_help_suffix =
-"Reads in a standard virtual password table in the current directory,
-and writes it out to a table.  The file names for the input and output
-tables are determined from the configuration file.";
+"Reads in a standard virtual password table in the current directory,\n"
+"and writes it out to a table.  The file names for the input and output\n"
+"tables are determined from the configuration file.";
 const char* cli_args_usage = "";
 const int cli_args_min = 0;
 const int cli_args_max = 0;
