--- commands/vpasswd2cdb.cc.orig	Mon Feb  2 14:55:24 2004
+++ commands/vpasswd2cdb.cc	Mon Feb  2 14:56:26 2004
@@ -27,9 +27,9 @@
 const char* cli_program = "vpasswd2cdb";
 const char* cli_help_prefix = "Converts text password tables to CDB format\n";
 const char* cli_help_suffix =
-"Reads in a standard virtual password table in the current directory,
-and writes it out to a CDB table.  The file names for the text and CDB
-tables are determined from the configuration file.";
+"Reads in a standard virtual password table in the current directory,\n"
+"and writes it out to a CDB table.  The file names for the text and CDB\n"
+"tables are determined from the configuration file.";
 const char* cli_args_usage = "";
 const int cli_args_min = 0;
 const int cli_args_max = 0;
