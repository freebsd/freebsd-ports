
$FreeBSD$

--- setup.sh.orig	Fri Jun  4 01:18:07 2004
+++ setup.sh	Sat Jun 19 21:59:35 2004
@@ -84,12 +84,12 @@
 echo "Unless you want to run multiple versions of Usermin at the same time"
 echo "you can just accept the defaults."
 echo ""
-printf "Config file directory [/etc/usermin]: "
+printf "Config file directory [%%PREFIX%%/etc/usermin]: "
 if [ "$config_dir" = "" ]; then
 	read config_dir
 fi
 if [ "$config_dir" = "" ]; then
-	config_dir=/etc/usermin
+	config_dir=%%PREFIX%%/etc/usermin
 fi
 abspath=`echo $config_dir | grep "^/"`
 if [ "$abspath" = "" ]; then
@@ -194,12 +194,12 @@
 	fi
 
 	# Ask for log directory
-	printf "Log file directory [/var/usermin]: "
+	printf "Log file directory [/var/log/usermin]: "
 	if [ "$var_dir" = "" ]; then
 		read var_dir
 	fi
 	if [ "$var_dir" = "" ]; then
-		var_dir=/var/usermin
+		var_dir=/var/log/usermin
 	fi
 	abspath=`echo $var_dir | grep "^/"`
 	if [ "$abspath" = "" ]; then
@@ -227,7 +227,9 @@
 	echo "Usermin is written entirely in Perl. Please enter the full path to the"
 	echo "Perl 5 interpreter on your system."
 	echo ""
-	if [ -x /usr/bin/perl ]; then
+	if [ -x %%PERL%% ]; then
+		perldef=%%PERL%%
+	elif [ -x /usr/bin/perl ]; then
 		perldef=/usr/bin/perl
 	elif [ -x /usr/local/bin/perl ]; then
 		perldef=/usr/local/bin/perl
@@ -465,7 +467,6 @@
 echo "Creating start and stop scripts.."
 rm -f $config_dir/stop $config_dir/start
 echo "#!/bin/sh" >>$config_dir/start
-echo "echo Starting Usermin server in $wadir" >>$config_dir/start
 echo "trap '' 1" >>$config_dir/start
 echo "LANG=" >>$config_dir/start
 echo "export LANG" >>$config_dir/start
