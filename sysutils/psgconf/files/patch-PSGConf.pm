--- ./lib/PSGConf.pm.orig	Thu Jan 24 15:59:07 2008
+++ ./lib/PSGConf.pm	Fri Feb  1 17:23:53 2008
@@ -39,7 +39,7 @@
 my %defaults = (
     config_dir      => "/usr/local/share/$myname/config",
     files_dir       => "/usr/local/share/$myname/files",
-    modules_file    => "/etc/${myname}_modules",
+    modules_file    => "/usr/local/etc/${myname}_modules",
     myname          => $myname,
     columns         => 80,
     verbose         => 0,
@@ -711,7 +711,7 @@
 =item modules_file
 
 Full path to B<psgconf> modules file.  Default is
-F</etc/psgconf_modules>.
+F</usr/local/etc/psgconf_modules>.
 
 =item tmpdir
 
