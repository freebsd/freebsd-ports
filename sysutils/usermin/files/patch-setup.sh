
$FreeBSD$

--- setup.sh.orig	Sat Apr  5 14:13:12 2003
+++ setup.sh	Sat Apr  5 22:59:09 2003
@@ -54,12 +54,12 @@
 echo "Unless you want to run multiple versions of Usermin at the same time"
 echo "you can just accept the defaults."
 echo ""
-printf "Config file directory [/etc/usermin]: "
+printf "Config file directory [!!PREFIX!!/etc/usermin]: "
 if [ "$config_dir" = "" ]; then
 	read config_dir
 fi
 if [ "$config_dir" = "" ]; then
-	config_dir=/etc/usermin
+	config_dir=!!PREFIX!!/etc/usermin
 fi
 abspath=`echo $config_dir | grep "^/"`
 if [ "$abspath" = "" ]; then
@@ -147,19 +147,19 @@
 else
 	# Config directory exists .. make sure it is not in use
 	ls $config_dir | grep -v rpmsave >/dev/null 2>&1
-	if [ "$?" = "0" -a "$config_dir" != "/etc/usermin" ]; then
+	if [ "$?" = "0" -a "$config_dir" != "!!PREFIX!!/etc/usermin" ]; then
 		echo "ERROR: Config directory $config_dir is not empty"
 		echo ""
 		exit 2
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
@@ -187,8 +187,8 @@
 	echo "Usermin is written entirely in Perl. Please enter the full path to the"
 	echo "Perl 5 interpreter on your system."
 	echo ""
-	if [ -x /usr/bin/perl ]; then
-		perldef=/usr/bin/perl
+	if [ -x !!PERL5!! ]; then
+		perldef=!!PERL5!!
 	elif [ -x /usr/local/bin/perl ]; then
 		perldef=/usr/local/bin/perl
 	else
@@ -427,7 +427,7 @@
 else
 	uname -a | grep -i FreeBSD >/dev/null
 	if [ "$?" = "0" ]; then
-		echo "LD_PRELOAD=/usr/lib/libpam.so.1" >>$config_dir/start
+		echo "LD_PRELOAD=/usr/lib/libpam.so" >>$config_dir/start
 		echo "export LD_PRELOAD" >>$config_dir/start
 	fi
 	echo "exec "$wadir/miniserv.pl" $config_dir/miniserv.conf" >>$config_dir/start
