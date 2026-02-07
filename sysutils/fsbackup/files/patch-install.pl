--- install.pl.orig	2005-01-14 10:54:36 UTC
+++ install.pl
@@ -23,10 +23,11 @@ $default_install_man = "/usr/local/man/m
 #-----------------------------------------------------------------------
 use Getopt::Long;
 
-GetOptions("prefix=s", \$prefix, "prefix-man=s", \$prefix_man);
+GetOptions("prefix=s", \$prefix, "prefix-man=s", \$prefix_man, "dest=s", \$dest);
 
 $prefix = defined($prefix) ? $prefix : $default_install_path;
 $prefix_man = defined($prefix_man) ? $prefix_man : $default_install_man;
+$dest = defined($dest) ? $dest : "";
 print "Installing to $prefix (man to $prefix_man)\n";
 
 chomp($prog_md5sum = `which md5sum`);
@@ -47,51 +48,51 @@ chomp($backup_name = `uname -n|tr '.' '_
 print "Makeing man page...\n";
 system ("pod2man fsbackup.pl > fsbackup.1");
 print "Installing man page to $prefix_man...\n";
-system ("cp -f fsbackup.1 $prefix_man/fsbackup.1");
-system ("chmod 644 $prefix_man/fsbackup.1");
+system ("cp -f fsbackup.1 $dest$prefix_man/fsbackup.1");
+system ("chmod 644 $dest$prefix_man/fsbackup.1");
 
 print "Creation directory tree in $prefix...\n";
 
-if (! -d $prefix){	
-    system ("mkdir $prefix");
-    system ("chmod 755 $prefix");
+if (! -d "$dest$prefix") {	
+    system ("mkdir $dest$prefix");
+    system ("chmod 755 $dest$prefix");
 }
-system ("mkdir $prefix/cache");
-system ("chmod 700 $prefix/cache");
-system ("mkdir $prefix/scripts");
-system ("chmod 700 $prefix/scripts");
-system ("mkdir $prefix/sys_backup");
-system ("chmod 700 $prefix/sys_backup");
+system ("mkdir $dest$prefix/cache");
+system ("chmod 700 $dest$prefix/cache");
+system ("mkdir $dest$prefix/scripts");
+system ("chmod 700 $dest$prefix/scripts");
+system ("mkdir $dest$prefix/sys_backup");
+system ("chmod 700 $dest$prefix/sys_backup");
 
 print "Installing fsbackup in $prefix...\n";
 
-system ("cp -f FAQ $prefix/FAQ");
-system ("chmod 644 $prefix/FAQ");
-system ("cp -f README $prefix/README");
-system ("chmod 644 $prefix/README");
-system ("cp -f VERSION $prefix/VERSION");
-system ("chmod 644 $prefix/VERSION");
-system ("cp -f fsbackup.1 $prefix/fsbackup.1");
-system ("chmod 644 $prefix/fsbackup.1");
+system ("cp -f FAQ $dest$prefix/FAQ");
+system ("chmod 644 $dest$prefix/FAQ");
+system ("cp -f README $dest$prefix/README");
+system ("chmod 644 $dest$prefix/README");
+system ("cp -f VERSION $dest$prefix/VERSION");
+system ("chmod 644 $dest$prefix/VERSION");
+system ("cp -f fsbackup.1 $dest$prefix/fsbackup.1");
+system ("chmod 644 $dest$prefix/fsbackup.1");
 
-copyfile("fsbackup.pl", "$prefix/fsbackup.pl");
-system ("chmod 711 $prefix/fsbackup.pl");
-copyfile("cfg_example", "$prefix/cfg_example");
-system ("chmod 600 $prefix/cfg_example");
-copyfile("create_backup.sh", "$prefix/create_backup.sh");
-system ("chmod 711 $prefix/create_backup.sh");
-copyfile("scripts/mysql_backup.sh", "$prefix/scripts/mysql_backup.sh");
-system ("chmod 711 $prefix/scripts/mysql_backup.sh");
-copyfile("scripts/sysbackup.sh", "$prefix/scripts/sysbackup.sh");
-system ("chmod 711 $prefix/scripts/sysbackup.sh");
-copyfile("scripts/fsrestore.sh", "$prefix/scripts/fsrestore.sh");
-system ("chmod 711 $prefix/scripts/fsrestore.sh");
-copyfile("scripts/pgsql_backup.sh", "$prefix/scripts/pgsql_backup.sh");
-system ("chmod 711 $prefix/scripts/pgsql_backup.sh");
-copyfile("scripts/sysrestore.sh", "$prefix/scripts/sysrestore.sh");
-system ("chmod 711 $prefix/scripts/sysrestore.sh");
-copyfile("scripts/sqlite_backup.sh", "$prefix/scripts/sqlite_backup.sh");
-system ("chmod 711 $prefix/scripts/sqlite_backup.sh");
+copyfile("fsbackup.pl", "$dest$prefix/fsbackup.pl");
+system ("chmod 711 $dest$prefix/fsbackup.pl");
+copyfile("cfg_example", "$dest$prefix/cfg_example");
+system ("chmod 600 $dest$prefix/cfg_example");
+copyfile("create_backup.sh", "$dest$prefix/create_backup.sh");
+system ("chmod 711 $dest$prefix/create_backup.sh");
+copyfile("scripts/mysql_backup.sh", "$dest$prefix/scripts/mysql_backup.sh");
+system ("chmod 711 $dest$prefix/scripts/mysql_backup.sh");
+copyfile("scripts/sysbackup.sh", "$dest$prefix/scripts/sysbackup.sh");
+system ("chmod 711 $dest$prefix/scripts/sysbackup.sh");
+copyfile("scripts/fsrestore.sh", "$dest$prefix/scripts/fsrestore.sh");
+system ("chmod 711 $dest$prefix/scripts/fsrestore.sh");
+copyfile("scripts/pgsql_backup.sh", "$dest$prefix/scripts/pgsql_backup.sh");
+system ("chmod 711 $dest$prefix/scripts/pgsql_backup.sh");
+copyfile("scripts/sysrestore.sh", "$dest$prefix/scripts/sysrestore.sh");
+system ("chmod 711 $dest$prefix/scripts/sysrestore.sh");
+copyfile("scripts/sqlite_backup.sh", "$dest$prefix/scripts/sqlite_backup.sh");
+system ("chmod 711 $dest$prefix/scripts/sqlite_backup.sh");
 
 print "* If you system not support MD5, please manually install module ./modules/Digest-Perl-MD5-1.5.tar.gz\n";
 print "* If Berkeley DB not installed and failed compilation of DB_File-1.77.tar.gz, please manually install DB from http://www.sleepycat.com.\n";
