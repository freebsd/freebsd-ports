--- setup.sh.orig
+++ setup.sh
@@ -13,6 +13,13 @@
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
@@ -113,7 +120,7 @@
 echo ""
 envetcdir="$config_dir"
 if [ "$envetcdir" = "" ]; then
-	envetcdir=/etc/webmin
+	envetcdir=%%PREFIX%%/etc/webmin
 	envetcdirnotfound=1
 fi
 printf "Config file directory [$envetcdir]: "
@@ -121,7 +128,7 @@
 	read config_dir
 fi
 if [ "$config_dir" = "" ]; then
-	config_dir=/etc/webmin
+	config_dir=%%PREFIX%%/etc/webmin
 fi
 abspath=`echo $config_dir | grep "^/"`
 if [ "$abspath" = "" ]; then
@@ -232,7 +239,7 @@
 else
 	# Config directory exists .. make sure it is not in use
 	ls $config_dir | grep -v rpmsave >/dev/null 2>&1
-	if [ "$?" = "0" -a "$config_dir" != "/etc/webmin" ]; then
+	if [ "$?" = "0" -a "$config_dir" != "%%PREFIX%%/etc/webmin" ]; then
 		echo "ERROR: Config directory $config_dir is not empty"
 		echo ""
 		exit 2
@@ -241,7 +248,7 @@
 	# Ask for log directory
 	envvardir="$var_dir"
 	if [ "$envvardir" = "" ]; then
-		envvardir=/var/webmin
+		envvardir=/var/db/webmin
 		envvardirnotfound=1
 	fi
 	printf "Log file directory [$envvardir]: "
@@ -249,7 +256,7 @@
 		read var_dir
 	fi
 	if [ "$var_dir" = "" ]; then
-		var_dir=/var/webmin
+		var_dir=/var/db/webmin
 	fi
 	abspath=`echo $var_dir | grep "^/"`
 	if [ "$abspath" = "" ]; then
