--- commands/vchforwards.cc.orig	Mon Feb  2 14:58:55 2004
+++ commands/vchforwards.cc	Mon Feb  2 14:59:29 2004
@@ -25,8 +25,7 @@
 const char* cli_help_prefix =
 "Change virtual user forwarding addresses.\n";
 const char* cli_help_suffix =
-"If no forwarding addresses are given, forwarding is disabled.
-";
+"If no forwarding addresses are given, forwarding is disabled.\n";
 const char* cli_args_usage = "USERNAME [DESTINATION1 ...]";
 const int cli_args_min = 1;
 const int cli_args_max = -1;
