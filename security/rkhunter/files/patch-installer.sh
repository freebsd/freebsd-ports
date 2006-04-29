--- installer.sh.orig	Mon Apr 25 13:24:56 2005
+++ installer.sh	Fri Apr 28 21:44:41 2006
@@ -119,15 +119,13 @@
 overwrite:programs_good.dat:/db/programs_good.dat:Database%%Program%%versions
 overwrite:defaulthashes.dat:/db/defaulthashes.dat:Database%%Default%%file%%hashes
 overwrite:md5blacklist.dat:/db/md5blacklist.dat:Database%%MD5%%blacklisted%%files
-overwrite:CHANGELOG:/docs/CHANGELOG:Changelog
-overwrite:README:/docs/README:Readme%%and%%FAQ
-overwrite:WISHLIST:/docs/WISHLIST:Wishlist%%and%%TODO
 "
 
 # Prefix: INSTALLDIR
 INSTALLFILES2="
-nooverwrite:rkhunter.conf:/usr/local/etc/rkhunter.conf:RK%%Hunter%%configuration%%file
-overwrite:rkhunter:/usr/local/bin/rkhunter:RK%%Hunter%%binary
+nooverwrite:rkhunter.conf:${INSTALLDIR}/etc/rkhunter.conf:RK%%Hunter%%configuration%%file
+overwrite:rkhunter.conf:${INSTALLDIR}/etc/rkhunter.conf.sample:RK%%Hunter%%sample%%configuration%%file
+overwrite:rkhunter:${INSTALLDIR}/bin/rkhunter:RK%%Hunter%%binary
 "
 
 # Create directories (only if they do not exist)
@@ -136,9 +134,7 @@
 ${INSTALLDIR}/etc
 ${INSTALLDIR}/bin
 ${INSTALLDIR}/lib/rkhunter/db
-${INSTALLDIR}/lib/rkhunter/docs
 ${INSTALLDIR}/lib/rkhunter/scripts
-${INSTALLDIR}/lib/rkhunter/tmp
 /usr/local/etc
 /usr/local/bin
 "
@@ -397,9 +393,6 @@
 #################################################################################
 
 
-# Clean active window
-clear
-
 echo "${INSTALLER_NAME} ${INSTALLER_VERSION} (${INSTALLER_COPYRIGHT})"
 echo $ECHOOPT "---------------"
 echo "Starting installation/update"
@@ -534,11 +527,14 @@
 done
 
 # Installation dir to configuration file
-INSTALLDIRCHECK=`cat /usr/local/etc/rkhunter.conf | grep "INSTALLDIR="`
+echo "" >> ${INSTALLDIR}/etc/rkhunter.conf.sample
+echo "INSTALLDIR=${INSTALLDIR}" >> ${INSTALLDIR}/etc/rkhunter.conf.sample
+
+INSTALLDIRCHECK=`cat ${INSTALLDIR}/etc/rkhunter.conf | grep "INSTALLDIR="`
 if [ "${INSTALLDIRCHECK}" = "" ]
   then
-    echo "" >> /usr/local/etc/rkhunter.conf
-    echo "INSTALLDIR=${INSTALLDIR}" >> /usr/local/etc/rkhunter.conf
+    echo "" >> ${INSTALLDIR}/etc/rkhunter.conf
+    echo "INSTALLDIR=${INSTALLDIR}" >> ${INSTALLDIR}/etc/rkhunter.conf
     echo "Configuration updated with installation path (${INSTALLDIR})"
   else
     echo "Configuration already updated."
@@ -548,7 +544,7 @@
 then
 	echo ""
 	echo $E "$t17"
-	echo "$t18 (/usr/local/bin/rkhunter)"
+	echo "$t18 (${INSTALLDIR}/rkhunter)"
 else
 	echo ""
 	echo $E "$t19"
