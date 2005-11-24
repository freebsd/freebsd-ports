--- ./lib/PSGConf.pm.orig	Mon Jun 21 21:17:31 2004
+++ ./lib/PSGConf.pm	Mon Jun 21 21:17:48 2004
@@ -34,8 +34,8 @@
 my %defaults = (
 	config_dir		=> '/usr/local/share/psgconf/config',
 	files_dir		=> '/usr/local/share/psgconf/files',
-	config_file		=> '/etc/psg.conf',
-	modules_file		=> '/etc/psgconf_modules',
+	config_file		=> '/usr/local/etc/psg.conf',
+	modules_file		=> '/usr/local/etc/psgconf_modules',
 	tmpdir			=> "/var/tmp/psgconf.$$",
 	verbose			=> 0,
 	do_fix			=> 0,
@@ -713,7 +713,7 @@
 =item config_file
 
 Full path to B<psgconf> config file (if applicable).  Default is
-F</etc/psg.conf>.
+F</usr/local/etc/psg.conf>.
 
 =item files_dir
 
@@ -723,7 +723,7 @@
 =item modules_file
 
 Full path to B<psgconf> modules file.  Default is
-F</etc/psgconf_modules>.
+F</usr/local/etc/psgconf_modules>.
 
 =item tmpdir
 
