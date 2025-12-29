--- setup.sh.orig
+++ setup.sh
@@ -6,6 +6,13 @@
 # Find install directory
 LANG=
 export LANG
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
@@ -93,12 +100,13 @@
 echo "Unless you want to run multiple versions of Usermin at the same time"
 echo "you can just accept the defaults."
 echo ""
-printf "Config file directory [/etc/usermin]: "
+printf "Config file directory [%%PREFIX%%/etc/usermin]: "
 if [ "$config_dir" = "" ]; then
-	read config_dir
+	config_dir="%%PREFIX%%/etc/usermin"
+	echo "%%PREFIX%%/etc/usermin"
 fi
 if [ "$config_dir" = "" ]; then
-	config_dir=/etc/usermin
+	config_dir=%%PREFIX%%/etc/usermin
 fi
 abspath=`echo $config_dir | grep "^/"`
 if [ "$abspath" = "" ]; then
@@ -202,19 +210,20 @@
 else
 	# Config directory exists .. make sure it is not in use
 	ls $config_dir | grep -v rpmsave >/dev/null 2>&1
-	if [ "$?" = "0" -a "$config_dir" != "/etc/usermin" ]; then
+	if [ "$?" = "0" -a "$config_dir" != "%%PREFIX%%/etc/usermin" ]; then
 		echo "ERROR: Config directory $config_dir is not empty"
 		echo ""
 		exit 2
 	fi
 
 	# Ask for log directory
-	printf "Log file directory [/var/usermin]: "
+	printf "Log file directory [/var/db/usermin]: "
 	if [ "$var_dir" = "" ]; then
-		read var_dir
+		var_dir="/var/db/usermin"
+		echo "/var/db/usermin"
 	fi
 	if [ "$var_dir" = "" ]; then
-		var_dir=/var/usermin
+		var_dir=/var/db/usermin
 	fi
 	abspath=`echo $var_dir | grep "^/"`
 	if [ "$abspath" = "" ]; then
@@ -252,7 +261,8 @@
 	if [ "$perl" = "" ]; then
 		if [ "$perldef" = "" ]; then
 			printf "Full path to perl: "
-			read perl
+			perl="%%PERL%%"
+			echo "%%PERL%%"
 			if [ "$perl" = "" ]; then
 				echo "ERROR: No path entered!"
 				echo ""
@@ -260,10 +270,8 @@
 			fi
 		else
 			printf "Full path to perl (default $perldef): "
-			read perl
-			if [ "$perl" = "" ]; then
-				perl=$perldef
-			fi
+			perl=$perldef
+			echo "$perldef"
 		fi
 	fi
 	echo ""
