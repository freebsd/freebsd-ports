--- perl5lib/LinuxDocTools.pm.orig	2023-06-12 16:57:27 UTC
+++ perl5lib/LinuxDocTools.pm
@@ -621,8 +621,20 @@ sub process_file {
     }
   }
 
+  my %EXPAND_locale = (
+    'ascii' => 'C',
+    'latin' => 'C',
+    'latin1' => 'C',
+    'utf-8' => 'C.UTF-8',
+    'nippon' => 'ja_JP.eucJP',
+    'euc-kr' => 'ko_KR.eucKR'
+  );
+  die "$error_header: Unkown character set $global->{charset}.\n"
+    unless exists $EXPAND_locale{$global->{charset}};
+  my $EXPAND_envvars = "LC_ALL=$EXPAND_locale{$global->{charset}}";
+
   my $sgmlsasp_command = "$main::progs->{SGMLSASP} $mapping < $preaspout |
-      expand -t $global->{tabsize} > $aspout";
+      $EXPAND_envvars expand -t $global->{tabsize} > $aspout";
   ldt_log "  ${error_header}::sgmlsasp_command:\n    $sgmlsasp_command";
   system ($sgmlsasp_command) == 0
     or die "$error_header: Error running $sgmlsasp_command. Aborting ...\n";
