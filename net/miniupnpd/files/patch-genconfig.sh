--- genconfig.sh.orig	2009-09-04 18:21:24.000000000 +0200
+++ genconfig.sh	2009-11-25 12:31:04.344410750 +0100
@@ -66,18 +66,25 @@
 		fi
 		# new way to see which one to use PF or IPF.
 		# see http://miniupnp.tuxfamily.org/forum/viewtopic.php?p=957
-		# source file with handy subroutines like checkyesno
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
+		# source file wource config file so we can probe vars
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
 		# TODO : Add support for IPFW
 		# echo "#define USE_IPFW 1" >> ${CONFIGFILE}
 		# FW=ipfw
