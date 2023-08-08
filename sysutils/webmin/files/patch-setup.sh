--- setup.sh.orig	2022-10-01 06:55:59 UTC
+++ setup.sh
@@ -13,6 +13,13 @@ if [ "$bootscript" = "" ]; then
 	bootscript="webmin"
 fi
 
+nostart="yes"
+nostop="yes"
+nochown="yes"
+nouninstall="yes"
+noperlpath="yes"
+atboot=0
+
 cd `dirname $0`
 if [ -x /bin/pwd ]; then
 	wadir=`/bin/pwd`
@@ -112,7 +119,7 @@ echo "you can just accept the defaults."
 echo ""
 envetcdir="$config_dir"
 if [ "$envetcdir" = "" ]; then
-	envetcdir=/etc/webmin
+	envetcdir=%%PREFIX%%/etc/webmin
 	envetcdirnotfound=1
 fi
 printf "Config file directory [$envetcdir]: "
@@ -120,7 +127,7 @@ if [ "$config_dir" = "" ]; then
 	read config_dir
 fi
 if [ "$config_dir" = "" ]; then
-	config_dir=/etc/webmin
+	config_dir=%%PREFIX%%/etc/webmin
 fi
 abspath=`echo $config_dir | grep "^/"`
 if [ "$abspath" = "" ]; then
@@ -214,7 +221,7 @@ if [ "$upgrading" = 1 ]; then
 	if [ $? != "0" ]; then
 		echo "logout=$config_dir/logout-flag" >> $config_dir/miniserv.conf
 	fi
-	
+
 	# Check for third-party modules in old version
 	if [ "$wadir" != "$oldwadir" ]; then
 		echo "Checking for third-party modules .."
@@ -231,7 +238,7 @@ if [ "$upgrading" = 1 ]; then
 else
 	# Config directory exists .. make sure it is not in use
 	ls $config_dir | grep -v rpmsave >/dev/null 2>&1
-	if [ "$?" = "0" -a "$config_dir" != "/etc/webmin" ]; then
+	if [ "$?" = "0" -a "$config_dir" != "%%PREFIX%%/etc/webmin" ]; then
 		echo "ERROR: Config directory $config_dir is not empty"
 		echo ""
 		exit 2
@@ -240,7 +247,7 @@ else
 	# Ask for log directory
 	envvardir="$var_dir"
 	if [ "$envvardir" = "" ]; then
-		envvardir=/var/webmin
+		envvardir=/var/db/webmin
 		envvardirnotfound=1
 	fi
 	printf "Log file directory [$envvardir]: "
@@ -248,7 +255,7 @@ else
 		read var_dir
 	fi
 	if [ "$var_dir" = "" ]; then
-		var_dir=/var/webmin
+		var_dir=/var/db/webmin
 	fi
 	abspath=`echo $var_dir | grep "^/"`
 	if [ "$abspath" = "" ]; then
@@ -305,7 +312,7 @@ else
 	fi
 	echo ""
 
-	# Test perl 
+	# Test perl
 	echo "Testing Perl .."
 	if [ ! -x $perl ]; then
 		echo "ERROR: Failed to find perl at $perl"
@@ -780,7 +787,7 @@ if [ -x "$systemctlcmd" ]; then
 
 	# Fix existing systemd webmin.service file to update start and stop commands
 	(cd "$wadir/init" ; WEBMIN_CONFIG=$config_dir WEBMIN_VAR=$var_dir "$wadir/init/updateboot.pl" "$bootscript")
-	
+
 	chmod 755 $config_dir/stop $config_dir/start $config_dir/restart $config_dir/restart-by-force-kill $config_dir/reload $config_dir/.pre-install $config_dir/.post-install
 else
 	# Creating symlinks
@@ -1053,5 +1060,3 @@ if [ "$oldwadir" != "$wadir" -a "$upgrading" = 1 -a "$
 	echo "version."
 	echo ""
 fi
-
-
