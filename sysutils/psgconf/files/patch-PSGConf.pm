--- ./lib/PSGConf.pm.orig	Sat Sep 23 13:44:35 2006
+++ ./lib/PSGConf.pm	Thu Jan 11 11:15:45 2007
@@ -14,6 +14,7 @@
 
 use strict;
 
+use File::Basename;
 use File::Copy;
 use File::Path;
 use File::stat;
@@ -34,8 +35,8 @@
 my %defaults = (
 	config_dir		=> '/usr/local/share/psgconf/config',
 	files_dir			=> '/usr/local/share/psgconf/files',
-	modules_file		=> '/etc/psgconf_modules',
-	tmpdir			=> "/var/tmp/$0.$$",
+	modules_file		=> '/usr/local/etc/psgconf_modules',
+	tmpdir			=> '/var/tmp/' . basename $0 . ".$$",
 	verbose			=> 0,
 	do_fix			=> 0,
 	restart_daemons	=> 1,
@@ -62,6 +63,7 @@
 
 	### Set from the environment variables if 
 	### not set on the command line.
+	$0 = basename $0;
 	$self->{tmpdir} = $ENV{'PSGCONF_TMPDIR'} . "/$0.$$"
 		if ( !defined $self->{tmpdir} && 
 			defined $ENV{'PSGCONF_TMPDIR'} && 
@@ -677,7 +679,7 @@
 =item modules_file
 
 Full path to B<psgconf> modules file.  Default is
-F</etc/psgconf_modules>.
+F</usr/local/etc/psgconf_modules>.
 
 =item tmpdir
 
