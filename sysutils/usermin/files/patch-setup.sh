--- setup.sh.orig	2015-02-15 03:16:25 UTC
+++ setup.sh
@@ -15,16 +15,8 @@
 srcdir=$wadir
 ver=`cat "$wadir/version"`
 
-# Find temp directory
-if [ "$tempdir" = "" ]; then
-	tempdir=$tempdir
-fi
-
-if [ $? != "0" ]; then
-	echo "ERROR: Cannot find the Usermin install directory";
-	echo "";
-	exit 1;
-fi
+tempdir=/tmp/.usermin
+mkdir -p $tempdir
 
 echo "***********************************************************************"
 echo "*            Welcome to the Usermin setup script, version $ver       *"
@@ -84,19 +76,7 @@
 echo "Unless you want to run multiple versions of Usermin at the same time"
 echo "you can just accept the defaults."
 echo ""
-printf "Config file directory [/etc/usermin]: "
-if [ "$config_dir" = "" ]; then
-	read config_dir
-fi
-if [ "$config_dir" = "" ]; then
-	config_dir=/etc/usermin
-fi
-abspath=`echo $config_dir | grep "^/"`
-if [ "$abspath" = "" ]; then
-	echo "Config directory must be an absolute path"
-	echo ""
-	exit 2
-fi
+config_dir=/usr/local/etc/usermin
 if [ ! -d $config_dir ]; then
 	mkdir $config_dir;
 	if [ $? != 0 ]; then
@@ -194,12 +174,12 @@
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
@@ -227,7 +207,9 @@
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
@@ -477,6 +459,7 @@
 
 fi
 
+noperlpath="yes"
 if [ "$noperlpath" = "" ]; then
 	echo "Inserting path to perl into scripts.."
 	(find "$wadir" -name '*.cgi' -print ; find "$wadir" -name '*.pl' -print) | $perl "$wadir/perlpath.pl" $perl -
@@ -487,7 +470,6 @@
 echo "Creating start and stop scripts.."
 rm -f $config_dir/stop $config_dir/start
 echo "#!/bin/sh" >>$config_dir/start
-echo "echo Starting Usermin server in $wadir" >>$config_dir/start
 echo "trap '' 1" >>$config_dir/start
 echo "LANG=" >>$config_dir/start
 echo "export LANG" >>$config_dir/start
@@ -600,6 +582,7 @@
 	echo passdelay=1 >> $config_dir/miniserv.conf
 fi
 
+nouninstall="yes"
 if [ "$nouninstall" = "" ]; then
 	echo "Creating uninstall script $config_dir/uninstall.sh .."
 	cat >$config_dir/uninstall.sh <<EOF
@@ -644,6 +627,7 @@
 	rm -f $config_dir/install-dir
 fi
 
+nostart="yes"
 if [ "$nostart" = "" ]; then
 	if [ "$inetd" != "1" ]; then
 		echo "Attempting to start Usermin mini web server.."
