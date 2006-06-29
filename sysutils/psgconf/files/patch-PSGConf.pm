--- ./lib/PSGConf.pm.orig	Wed May  3 08:55:41 2006
+++ ./lib/PSGConf.pm	Thu May  4 10:21:24 2006
@@ -34,7 +34,7 @@
 my %defaults = (
 	config_dir		=> '/usr/local/share/psgconf/config',
 	files_dir			=> '/usr/local/share/psgconf/files',
-	modules_file		=> '/etc/psgconf_modules',
+	modules_file		=> '/usr/local/etc/psgconf_modules',
 	tmpdir			=> "/var/tmp/psgconf.$$",
 	verbose			=> 0,
 	do_fix			=> 0,
@@ -678,7 +678,7 @@
 =item modules_file
 
 Full path to B<psgconf> modules file.  Default is
-F</etc/psgconf_modules>.
+F</usr/local/etc/psgconf_modules>.
 
 =item tmpdir
 
