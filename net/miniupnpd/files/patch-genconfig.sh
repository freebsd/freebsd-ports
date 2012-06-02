--- genconfig.sh.orig	2012-05-24 20:05:47.000000000 +0200
+++ genconfig.sh	2012-05-30 20:12:57.685877655 +0200
@@ -112,18 +112,20 @@
 		# new way to see which one to use PF or IPF.
 		# see http://miniupnp.tuxfamily.org/forum/viewtopic.php?p=957
 		# source file with handy subroutines like checkyesno
-		. /etc/rc.subr
-		# source config file so we can probe vars
-		. /etc/rc.conf
-		if checkyesno ipfilter_enable; then
-			echo "Using ipf"
-			FW=ipf
-		elif checkyesno pf_enable; then
-			echo "Using pf"
-			FW=pf
-		elif checkyesno firewall_enable; then
-			echo "Using ifpw"
-			FW=ipfw
+		if [ -f /etc/rc.subr ] && [ -f /etc/rc.conf ]; then
+			. /etc/rc.subr
+			# source config file so we can probe vars
+			. /etc/rc.conf
+			if checkyesno ipfilter_enable; then
+				echo "Using ipf"
+				FW=ipf
+			elif checkyesno pf_enable; then
+				echo "Using pf"
+				FW=pf
+			elif checkyesno firewall_enable; then
+				echo "Using ifpw"
+				FW=ipfw
+			fi
 		else
 			echo "Could not detect usage of ipf, pf, ipfw. Compiling for pf by default"
 			FW=pf
