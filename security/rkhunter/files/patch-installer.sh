--- installer.sh.orig	Sun Jul 25 16:20:28 2004
+++ installer.sh	Sun Jul 25 17:19:48 2004
@@ -69,6 +69,7 @@
           ;;
       *)
           echo "Wrong parameter"
+          exit
 	  ;;
   esac
   shift
@@ -111,21 +112,18 @@
 overwrite:check_port.pl:/scripts/check_port.pl:Portscanner
 overwrite:filehashmd5.pl:/scripts/filehashmd5.pl:MD5%%Digest%%generator
 overwrite:filehashsha1.pl:/scripts/filehashsha1.pl:SHA1%%Digest%%generator
-verwrite:showfiles.pl:/scripts/showfiles.pl:Directory%%viewer
+overwrite:showfiles.pl:/scripts/showfiles.pl:Directory%%viewer
 overwrite:backdoorports.dat:/db/backdoorports.dat:Database%%Backdoor%%ports
 overwrite:mirrors.dat:/db/mirrors.dat:Database%%Update%%mirrors
 overwrite:os.dat:/db/os.dat:Database%%Operating%%Systems
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
@@ -134,10 +132,7 @@
 ${INSTALLDIR}/etc
 ${INSTALLDIR}/bin
 ${INSTALLDIR}/lib/rkhunter/db
-${INSTALLDIR}/lib/rkhunter/docs
 ${INSTALLDIR}/lib/rkhunter/scripts
-${INSTALLDIR}/lib/rkhunter/tmp
-/usr/local/etc
 "
 
 CHECKDIR="/usr/local"
@@ -345,8 +340,6 @@
 
 
 # Clean active window
-clear
-
 echo "${INSTALLER_NAME} ${INSTALLER_VERSION} (${INSTALLER_COPYRIGHT})"
 echo $ECHOOPT "---------------"
 echo "Starting installation/update"
@@ -467,7 +460,7 @@
   if [ -f ${INSTALLPREFIX}${CURFILE} ]
     then
       #error redirection in .rkhunter it's just for a clear display if user run not as root
-      cp -f ${INSTALLPREFIX}${CURFILE} ${NEWFILE} 2> ~/.rkhunter.log
+      cp -f ${INSTALLPREFIX}${CURFILE} "${INSTALLDIR}/${NEWFILE}" 2> ~/.rkhunter.log
       if [ $? -eq 0 ]
         then
 	  echo $E "OK"
@@ -482,10 +475,10 @@
  
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
@@ -495,7 +488,7 @@
 then
 	echo ""
 	echo $E "$t17"
-	echo "$t18 (/usr/local/bin/rkhunter)"
+	echo "$t18 (${INSTALLDIR}/bin/rkhunter)"
 else
 	echo ""
 	echo $E "$t19"
