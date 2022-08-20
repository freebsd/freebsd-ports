--- setup.sh.orig	2022-07-26 22:01:51 UTC
+++ setup.sh
@@ -15,17 +15,9 @@ fi
 srcdir=$wadir
 ver=`cat "$wadir/version"`
 
-# Find temp directory
-if [ "$tempdir" = "" ]; then
-	tempdir=$tempdir
-fi
+tempdir=/tmp/.usermin
+mkdir -p $tempdir
 
-if [ $? != "0" ]; then
-	echo "ERROR: Cannot find the Usermin install directory";
-	echo "";
-	exit 1;
-fi
-
 echo "***********************************************************************"
 echo "*            Welcome to the Usermin setup script, version $ver       *"
 echo "***********************************************************************"
@@ -93,19 +85,7 @@ echo "Usermin uses separate directories for configurat
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
@@ -203,12 +183,12 @@ else
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
@@ -236,7 +216,9 @@ else
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
@@ -495,6 +477,7 @@ EOF
 
 fi
 
+noperlpath="yes"
 if [ "$noperlpath" = "" ]; then
 	echo "Inserting path to perl into scripts .."
 	(find "$wadir" -name '*.cgi' -print ; find "$wadir" -name '*.pl' -print) | $perl "$wadir/perlpath.pl" $perl -
@@ -506,7 +489,6 @@ fi
 echo "Creating start and stop init scripts .."
 # Start main
 echo "#!/bin/sh" >$config_dir/.start-init
-echo "echo Starting Usermin server in $wadir" >>$config_dir/.start-init
 echo "trap '' 1" >>$config_dir/.start-init
 echo "LANG=" >>$config_dir/.start-init
 echo "export LANG" >>$config_dir/.start-init
@@ -701,6 +683,7 @@ if [ "$?" != "0" ]; then
 	echo passdelay=1 >> $config_dir/miniserv.conf
 fi
 
+nouninstall="yes"
 if [ "$nouninstall" = "" ]; then
 	echo "Creating uninstall script $config_dir/uninstall.sh .."
 	cat >$config_dir/uninstall.sh <<EOF
@@ -764,6 +747,7 @@ if [ -r "$srcdir/setup-post.sh" ]; then
 	. "$srcdir/setup-post.sh"
 fi
 
+nostart="yes"
 if [ "$nostart" = "" ]; then
 	if [ "$inetd" != "1" ]; then
 		action="start"
