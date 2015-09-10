--- setup.sh.orig	2015-03-13 23:51:36 UTC
+++ setup.sh
@@ -17,16 +17,8 @@
 srcdir=$wadir
 ver=`cat "$wadir/version"`
 
-# Find temp directory
-if [ "$tempdir" = "" ]; then
-	tempdir=/tmp/.webmin
-fi
-
-if [ $? != "0" ]; then
-	echo "ERROR: Cannot find the Webmin install directory";
-	echo "";
-	exit 1;
-fi
+tempdir=/tmp/.webmin
+mkdir -p $tempdir
 
 echo "***********************************************************************"
 echo "*            Welcome to the Webmin setup script, version $ver        *"
@@ -97,19 +89,7 @@
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
@@ -209,12 +189,12 @@
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
@@ -242,7 +222,9 @@
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
@@ -441,22 +423,6 @@
 		fi
 	fi
 
-	# Ask whether to run at boot time
-	if [ "$atboot" = "" ]; then
-		initsupp=`grep "^os_support=" "$srcdir/init/module.info" | sed -e 's/os_support=//g' | grep $os_type`
-		atboot=0
-		if [ "$initsupp" != "" ]; then
-			printf "Start Webmin at boot time (y/n): "
-			read atbootyn
-			if [ "$atbootyn" = "y" -o "$atbootyn" = "Y" ]; then
-				atboot=1
-				makeboot=1
-			fi
-		else
-			echo "Webmin does not support being started at boot time on your system."
-		fi
-	fi
-
 	# Copy files to target directory
 	echo "***********************************************************************"
 	if [ "$wadir" != "$srcdir" ]; then
@@ -578,6 +544,7 @@
 	fi
 fi
 
+noperlpath="yes"
 if [ "$noperlpath" = "" ]; then
 	echo "Inserting path to perl into scripts.."
 	(find "$wadir" -name '*.cgi' -print ; find "$wadir" -name '*.pl' -print) | $perl "$wadir/perlpath.pl" $perl -
@@ -588,7 +555,6 @@
 echo "Creating start and stop scripts.."
 rm -f $config_dir/stop $config_dir/start $config_dir/restart $config_dir/reload
 echo "#!/bin/sh" >>$config_dir/start
-echo "echo Starting Webmin server in $wadir" >>$config_dir/start
 echo "trap '' 1" >>$config_dir/start
 echo "LANG=" >>$config_dir/start
 echo "export LANG" >>$config_dir/start
@@ -724,6 +690,7 @@
 	echo passdelay=1 >> $config_dir/miniserv.conf
 fi
 
+nouninstall="yes"
 if [ "$nouninstall" = "" ]; then
 	echo "Creating uninstall script $config_dir/uninstall.sh .."
 	cat >$config_dir/uninstall.sh <<EOF
@@ -761,6 +728,7 @@
 	chmod -R og-rw $config_dir/$f
 done
 chmod +r $config_dir/version
+nochown="yes"
 if [ "$nochown" = "" ]; then
 	# Make program directory non-world-writable, but executable
 	chown -R root "$wadir"
@@ -813,6 +781,7 @@
 	. "$srcdir/setup-post.sh"
 fi
 
+nostart="yes"
 if [ "$nostart" = "" ]; then
 	if [ "$inetd" != "1" ]; then
 		echo "Attempting to start Webmin mini web server.."
