--- installer.sh.old	Sun Aug  8 00:16:28 2004
+++ installer.sh	Sun Aug  8 00:21:52 2004
@@ -120,15 +120,12 @@
 overwrite:programs_good.dat:/db/programs_good.dat:Database%%Program%%versions
 overwrite:defaulthashes.dat:/db/defaulthashes.dat:Database%%Default%%file%%hashes
 overwrite:md5blacklist.dat:/db/md5blacklist.dat:Database%%MD5%%blacklisted%%files
-overwrite:CHANGELOG:/docs/CHANGELOG:Changelog
-overwrite:README:/docs/README:Readme%%and%%FAQ
-overwrite:WISHLIST:/docs/WISHLIST:Wishlist%%and%%TODO
 "
 
 # Prefix: INSTALLDIR
 INSTALLFILES2="
-overwrite:rkhunter.conf:/usr/local/etc/rkhunter.conf:RK%%Hunter%%configuration%%file
-overwrite:rkhunter:/usr/local/bin/rkhunter:RK%%Hunter%%binary
+overwrite:rkhunter.conf:/etc/rkhunter.conf.sample:RK%%Hunter%%configuration%%file
+overwrite:rkhunter:/bin/rkhunter:RK%%Hunter%%binary
 "
 
 # Create directories (only if they do not exist)
@@ -137,10 +134,7 @@
 ${INSTALLDIR}/etc
 ${INSTALLDIR}/bin
 ${INSTALLDIR}/lib/rkhunter/db
-${INSTALLDIR}/lib/rkhunter/docs
 ${INSTALLDIR}/lib/rkhunter/scripts
-${INSTALLDIR}/lib/rkhunter/tmp
-/usr/local/etc
 "
 
 CHECKDIR="/usr/local"
@@ -347,9 +341,6 @@
 #################################################################################
 
 
-# Clean active window
-clear
-
 echo "${INSTALLER_NAME} ${INSTALLER_VERSION} (${INSTALLER_COPYRIGHT})"
 echo $ECHOOPT "---------------"
 echo "Starting installation/update"
@@ -470,7 +461,7 @@
   if [ -f ${INSTALLPREFIX}${CURFILE} ]
     then
       #error redirection in .rkhunter it's just for a clear display if user run not as root
-      cp -f ${INSTALLPREFIX}${CURFILE} ${NEWFILE} 2> ~/.rkhunter.log
+      cp -f ${INSTALLPREFIX}${CURFILE} "${INSTALLDIR}/${NEWFILE}" 2> ~/.rkhunter.log
       if [ $? -eq 0 ]
         then
 	  echo $E "OK"
@@ -485,10 +476,10 @@
  
 done
 
-INSTALLDIRCHECK=`cat /usr/local/etc/rkhunter.conf | grep "INSTALLDIR="`
+INSTALLDIRCHECK=`cat $INSTALLDIR/etc/rkhunter.conf.sample | grep "INSTALLDIR="`
 if [ "${INSTALLDIRCHECK}" = "" ]
   then
-    echo "INSTALLDIR=${INSTALLDIR}" >> /usr/local/etc/rkhunter.conf
+    echo "INSTALLDIR=${INSTALLDIR}" >> $INSTALLDIR/etc/rkhunter.conf.sample
     echo "Configuration updated with installation path (${INSTALLDIR})"
   else
     echo "Configuration already updated."
@@ -498,7 +489,7 @@
 then
 	echo ""
 	echo $E "$t17"
-	echo "$t18 (/usr/local/bin/rkhunter)"
+	echo "$t18 (${INSTALLDIR}/bin/rkhunter)"
 else
 	echo ""
 	echo $E "$t19"
