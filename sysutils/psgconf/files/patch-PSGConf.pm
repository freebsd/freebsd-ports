--- ./lib/PSGConf.pm.orig	Sat Sep 23 13:44:35 2006
+++ ./lib/PSGConf.pm	Thu Jan 11 11:15:45 2007
@@ -34,8 +34,8 @@
 my %defaults = (
 	config_dir		=> '/usr/local/share/psgconf/config',
 	files_dir			=> '/usr/local/share/psgconf/files',
-	modules_file		=> '/etc/psgconf_modules',
+	modules_file		=> '/usr/local/etc/psgconf_modules',
 	tmpdir			=> '/var/tmp/' . basename $0 . ".$$",
 	verbose			=> 0,
 	do_fix			=> 0,
 	restart_daemons	=> 1,
@@ -677,7 +677,7 @@
 =item modules_file
 
 Full path to B<psgconf> modules file.  Default is
-F</etc/psgconf_modules>.
+F</usr/local/etc/psgconf_modules>.
 
 =item tmpdir
 
