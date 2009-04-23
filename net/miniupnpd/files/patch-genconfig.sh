--- genconfig.sh.orig	2008-10-01 14:49:26.000000000 +0200
+++ genconfig.sh	2009-04-19 14:15:37.574904740 +0200
@@ -70,17 +70,24 @@
 		# new way to see which one to use PF or IPF.
 		# see http://miniupnp.tuxfamily.org/forum/viewtopic.php?p=957
 		# source file with handy subroutines like checkyesno
-		. /etc/rc.subr
-		# source config file so we can probe vars
-		. /etc/rc.conf
-		if checkyesno ipfilter_enable; then
-			echo "Using ipf"
-			FW=ipf
-			echo "#define USE_IPF 1" >> ${CONFIGFILE}
-		elif checkyesno pf_enable; then
-			echo "Using pf"
-			FW=pf
-			echo "#define USE_PF 1" >> ${CONFIGFILE}
+		if [ -f /etc/rc.subr ] && [ -f /etc/rc.conf ]; then
+			# source file with handy subroutines like checkyesno
+			. /etc/rc.subr
+			# source config file so we can probe vars
+			. /etc/rc.conf
+			if checkyesno ipfilter_enable; then
+				echo "Using ipf"
+				FW=ipf
+				echo "#define USE_IPF 1" >> ${CONFIGFILE}
+			elif checkyesno pf_enable; then
+				echo "Using pf"
+				FW=pf
+				echo "#define USE_PF 1" >> ${CONFIGFILE}
+			else
+				echo "Could not detect usage of ipf or pf. Compiling for pf by default"
+				FW=pf
+				echo "#define USE_PF 1" >> ${CONFIGFILE}
+			fi
 		else
 			echo "Could not detect usage of ipf or pf. Compiling for pf by default"
 			FW=pf
