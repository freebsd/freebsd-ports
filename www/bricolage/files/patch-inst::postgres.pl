--- inst/postgres.pl.orig	Thu Feb 19 08:37:08 2004
+++ inst/postgres.pl	Sun May 23 11:58:05 2004
@@ -36,15 +36,19 @@
 use File::Spec::Functions;
 use Data::Dumper;
 
+# check whether questions should be asked
+our $QUIET;
+$QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+
 print "\n\n==> Probing PostgreSQL Configuration <==\n\n";
 
 our %PG;
 
 # setup some defaults
-$PG{root_user} = 'postgres';
+$PG{root_user} = 'pgsql';
 $PG{root_pass} = '';
 $PG{sys_user}  = 'bric';
-$PG{sys_pass}  = 'NONE';
+$PG{sys_pass}  = ''; # Ask the user to deal with it
 $PG{db_name}   = 'bric';
 $PG{host_name} = '';
 $PG{host_port} = '';
@@ -58,8 +62,9 @@
 get_bin_dir();
 get_psql();
 get_version();
-get_users();
-get_host();
+# Skip for automated installation
+#get_users();
+#get_host();
 get_version();
 
 # all done, dump out apache database, announce success and exit
@@ -122,13 +127,18 @@
 # ask the user for user settings
 sub get_users {
     print "\n";
-    ask_confirm("Postgres Root Username", \$PG{root_user});
+    if ($QUIET) {
+        print "Postgres Root Username ". $PG{root_user} ."\n";
+    }
+    else {
+        ask_confirm("Postgres Root Username", \$PG{root_user});
+    }
     ask_confirm("Postgres Root Password (leave empty for no password)",
 		\$PG{root_pass});
 
     while(1) {
 	$PG{system_user} = $PG{root_user};
-	ask_confirm("Postgres System Username", \$PG{system_user});
+        ask_confirm("Postgres System Username", \$PG{system_user}) unless $QUIET;
 	$PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
 	last if defined $PG{system_user_uid};
 	print "User \"$PG{system_user}\" not found!  This user must exist ".
