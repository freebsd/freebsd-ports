--- plugins-scripts/check_mysql_health.pl.orig	2014-12-07 18:44:47.220159275 +0000
+++ plugins-scripts/check_mysql_health.pl	2014-12-07 18:51:34.356136684 +0000
@@ -353,8 +353,8 @@
   $needs_restart = 1;
   # if the calling script has a path for shared libs and there is no --environment
   # parameter then the called script surely needs the variable too.
-  foreach my $important_env qw(LD_LIBRARY_PATH SHLIB_PATH 
-      ORACLE_HOME TNS_ADMIN ORA_NLS ORA_NLS33 ORA_NLS10) {
+  foreach my $important_env (qw(LD_LIBRARY_PATH SHLIB_PATH 
+      ORACLE_HOME TNS_ADMIN ORA_NLS ORA_NLS33 ORA_NLS10)) {
     if ($ENV{$important_env} && ! scalar(grep { /^$important_env=/ } 
         keys %{$commandline{environment}})) {
       $commandline{environment}->{$important_env} = $ENV{$important_env};
