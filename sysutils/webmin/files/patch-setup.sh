--- setup.sh.orig	2020-07-01 17:46:39 UTC
+++ setup.sh
@@ -17,17 +17,9 @@ fi
 srcdir=$wadir
 ver=`cat "$wadir/version"`
 
-# Find temp directory
-if [ "$tempdir" = "" ]; then
-	tempdir=/tmp/.webmin
-fi
+tempdir=/tmp/.webmin
+mkdir -p $tempdir
 
-if [ $? != "0" ]; then
-	echo "ERROR: Cannot find the Webmin install directory";
-	echo "";
-	exit 1;
-fi
-
 echo "***********************************************************************"
 echo "*            Welcome to the Webmin setup script, version $ver        *"
 echo "***********************************************************************"
@@ -98,19 +90,7 @@ echo "Webmin uses separate directories for configurati
 echo "Unless you want to run multiple versions of Webmin at the same time"
 echo "you can just accept the defaults."
 echo ""
-printf "Config file directory [/etc/webmin]: "
-if [ "$config_dir" = "" ]; then
-	read config_dir
-fi
-if [ "$config_dir" = "" ]; then
-	config_dir=/etc/webmin
-fi
-abspath=`echo $config_dir | grep "^/"`
-if [ "$abspath" = "" ]; then
-	echo "Config directory must be an absolute path"
-	echo ""
-	exit 2
-fi
+config_dir=/usr/local/etc/webmin
 if [ ! -d $config_dir ]; then
 	mkdir $config_dir;
 	if [ $? != 0 ]; then
@@ -210,12 +190,12 @@ else
 	fi
 
 	# Ask for log directory
-	printf "Log file directory [/var/webmin]: "
+	printf "Log file directory [/var/log/webmin]: "
 	if [ "$var_dir" = "" ]; then
 		read var_dir
 	fi
 	if [ "$var_dir" = "" ]; then
-		var_dir=/var/webmin
+		var_dir=/var/log/webmin
 	fi
 	abspath=`echo $var_dir | grep "^/"`
 	if [ "$abspath" = "" ]; then
@@ -243,7 +223,9 @@ else
 	echo "Webmin is written entirely in Perl. Please enter the full path to the"
 	echo "Perl 5 interpreter on your system."
 	echo ""
-	if [ -x /usr/bin/perl ]; then
+	if [ -x %%PERL%% ]; then
+		perldef=%%PERL%%
+	elif [ -x /usr/bin/perl ]; then
 		perldef=/usr/bin/perl
 	elif [ -x /usr/local/bin/perl ]; then
 		perldef=/usr/local/bin/perl
@@ -444,6 +426,7 @@ else
 		fi
 	fi
 
+	atboot=0
 	# Ask whether to run at boot time
 	if [ "$atboot" = "" ]; then
 		if echo "$os_type" | grep  -q "\-linux$"; then
@@ -593,6 +576,7 @@ EOF
 	fi
 fi
 
+noperlpath="yes"
 if [ "$noperlpath" = "" ]; then
 	echo "Inserting path to perl into scripts.."
 	(find "$wadir" -name '*.cgi' -print ; find "$wadir" -name '*.pl' -print) | $perl "$wadir/perlpath.pl" $perl -
@@ -603,7 +587,6 @@ fi
 echo "Creating start and stop scripts.."
 rm -f $config_dir/stop $config_dir/start $config_dir/restart $config_dir/reload
 echo "#!/bin/sh" >>$config_dir/start
-echo "echo Starting Webmin server in $wadir" >>$config_dir/start
 echo "trap '' 1" >>$config_dir/start
 echo "LANG=" >>$config_dir/start
 echo "export LANG" >>$config_dir/start
@@ -754,6 +737,7 @@ if [ "$?" != "0" ]; then
 	echo passdelay=1 >> $config_dir/miniserv.conf
 fi
 
+nouninstall="yes"
 if [ "$nouninstall" = "" ]; then
 	echo "Creating uninstall script $config_dir/uninstall.sh .."
 	cat >$config_dir/uninstall.sh <<EOF
@@ -791,6 +775,7 @@ for f in miniserv.conf miniserv.pem miniserv.users; do
 	chmod -R og-rw $config_dir/$f
 done
 chmod +r $config_dir/version
+nochown="yes"
 if [ "$nochown" = "" ]; then
 	# Make program directory non-world-writable, but executable
 	chown -R root "$wadir"
@@ -843,6 +828,7 @@ if [ -r "$srcdir/setup-post.sh" ]; then
 	. "$srcdir/setup-post.sh"
 fi
 
+nostart="yes"
 if [ "$nostart" = "" ]; then
 	if [ "$inetd" != "1" ]; then
 		echo "Attempting to start Webmin mini web server.."
