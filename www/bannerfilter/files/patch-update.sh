--- update.sh.orig	Mon May 31 23:52:25 2004
+++ update.sh	Sun Aug 14 17:51:57 2005
@@ -21,14 +21,21 @@
 # running as, or if you don't have killall, change RELOAD to 0.
 
 # Choose your HTTP downloader:
-CMD="lynx -source"
+# CMD="lynx -source"
 # CMD="wget -q -O -"
 # CMD="curl -s"
+CMD="fetch -q -o -"
 
 # Reload with "killall -HUP redirector.pl" if the files have changed?
 RELOAD=1
 # RELOAD=0
 
+# Directory with the data files
+CONFIGDIR="/usr/local/etc/bannerfilter"
+
+# temp dir
+TEMPDIR="/tmp"
+
 ##########################################################################
 
 # Earliest version of BannerFilter compatible with your data files:
@@ -37,18 +44,18 @@
 # Read the data files from the current directory, and get the modification
 # date from each.  Redirect errors to /dev/null.  If the files don't exist,
 # we get blank values.
-OLDBANNERS=`grep "^# last modified " banners.data 2>/dev/null|cut -d " " -f4`
-OLDPOPUPS=`grep "^# last modified " popups.data 2>/dev/null|cut -d " " -f4`
-OLDFRAMES=`grep "^# last modified " frames.data 2>/dev/null|cut -d " " -f4`
-OLDEXCEPTIONS=`grep "^# last modified " exceptions.data 2>/dev/null|cut -d " " -f4`
+OLDBANNERS=`grep "^# last modified " $CONFIGDIR/banners.data 2>/dev/null|cut -d " " -f4`
+OLDPOPUPS=`grep "^# last modified " $CONFIGDIR/popups.data 2>/dev/null|cut -d " " -f4`
+OLDFRAMES=`grep "^# last modified " $CONFIGDIR/frames.data 2>/dev/null|cut -d " " -f4`
+OLDEXCEPTIONS=`grep "^# last modified " $CONFIGDIR/exceptions.data 2>/dev/null|cut -d " " -f4`
 
 # Get the earliest version of BannerFilter compatible with the
 # new data files, and see whether we need to upgrade
-$CMD http://phroggy.com/bannerfilter/version.txt>version.tmp \
+$CMD http://phroggy.com/bannerfilter/version.txt> $TEMPDIR/version.tmp \
 || { echo "Error retrieving version.txt"; exit; }
-if ( grep "^version " version.tmp>/dev/null ); then
-  NEW=`grep "^version " version.tmp|cut -d " " -f2`
-  rm version.tmp
+if ( grep "^version " $TEMPDIR/version.tmp>/dev/null ); then
+  NEW=`grep "^version " $TEMPDIR/version.tmp|cut -d " " -f2`
+  rm $TEMPDIR/version.tmp
 else
   echo "Error: something unexpected in version.txt"
   exit
@@ -64,55 +71,63 @@
 
 # Download all four data files
 
-$CMD http://phroggy.com/bannerfilter/banners.data>banners.data.tmp \
-&& grep "^# banners.data$" banners.data.tmp>/dev/null \
+$CMD http://phroggy.com/bannerfilter/banners.data>$CONFIGDIR/banners.data.tmp \
+&& grep "^# banners.data$" $CONFIGDIR/banners.data.tmp>/dev/null \
 || { echo "Error retrieving banners.data"; exit; }
 
-$CMD http://phroggy.com/bannerfilter/popups.data>popups.data.tmp \
-&& grep "^# popups.data$" popups.data.tmp>/dev/null \
+$CMD http://phroggy.com/bannerfilter/popups.data>$CONFIGDIR/popups.data.tmp \
+&& grep "^# popups.data$" $CONFIGDIR/popups.data.tmp>/dev/null \
 || { echo "Error retrieving popups.data"; exit; }
 
-$CMD http://phroggy.com/bannerfilter/frames.data>frames.data.tmp \
-&& grep "^# frames.data$" frames.data.tmp>/dev/null \
+$CMD http://phroggy.com/bannerfilter/frames.data>$CONFIGDIR/frames.data.tmp \
+&& grep "^# frames.data$" $CONFIGDIR/frames.data.tmp>/dev/null \
 || { echo "Error retrieving frames.data"; exit; }
 
-$CMD http://phroggy.com/bannerfilter/exceptions.data>exceptions.data.tmp \
-&& grep "^# exceptions.data$" exceptions.data.tmp>/dev/null \
+$CMD http://phroggy.com/bannerfilter/exceptions.data>$CONFIGDIR/exceptions.data.tmp \
+&& grep "^# exceptions.data$" $CONFIGDIR/exceptions.data.tmp>/dev/null \
 || { echo "Error retrieving exceptions.data"; exit; }
 
 # Get the modification dates of the files we just downloaded, compare
 # them to what we already have, and only overwrite if necessary.
 # By using cat to overwrite, we preserve ownership and permissions.
 
-NEWBANNERS=`grep "^# last modified " banners.data.tmp|cut -d " " -f4`
-NEWPOPUPS=`grep "^# last modified " popups.data.tmp|cut -d " " -f4`
-NEWFRAMES=`grep "^# last modified " frames.data.tmp|cut -d " " -f4`
-NEWEXCEPTIONS=`grep "^# last modified " exceptions.data.tmp|cut -d " " -f4`
+NEWBANNERS=`grep "^# last modified " $CONFIGDIR/banners.data.tmp|cut -d " " -f4`
+NEWPOPUPS=`grep "^# last modified " $CONFIGDIR/popups.data.tmp|cut -d " " -f4`
+NEWFRAMES=`grep "^# last modified " $CONFIGDIR/frames.data.tmp|cut -d " " -f4`
+NEWEXCEPTIONS=`grep "^# last modified " $CONFIGDIR/exceptions.data.tmp|cut -d " " -f4`
 CHANGED=0
 if [ "$OLDBANNERS" != "$NEWBANNERS" ]; then
-  cat banners.data.tmp > banners.data
+  cat $CONFIGDIR/banners.data.tmp > $CONFIGDIR/banners.data
   CHANGED=1
 fi
 if [ "$OLDPOPUPS" != "$NEWPOPUPS" ]; then
-  cat popups.data.tmp > popups.data
+  cat $CONFIGDIR/popups.data.tmp > $CONFIGDIR/popups.data
   CHANGED=1
 fi
 if [ "$OLDFRAMES" != "$NEWFRAMES" ]; then
-  cat frames.data.tmp > frames.data
+  cat $CONFIGDIR/frames.data.tmp > $CONFIGDIR/frames.data
   CHANGED=1
 fi
 if [ "$OLDEXCEPTIONS" != "$NEWEXCEPTIONS" ]; then
-  cat exceptions.data.tmp > exceptions.data
+  cat $CONFIGDIR/exceptions.data.tmp > $CONFIGDIR/exceptions.data
   CHANGED=1
 fi
 
 # Clean up our temp files
-rm banners.data.tmp
-rm popups.data.tmp
-rm frames.data.tmp
-rm exceptions.data.tmp
+rm $CONFIGDIR/banners.data.tmp
+rm $CONFIGDIR/popups.data.tmp
+rm $CONFIGDIR/frames.data.tmp
+rm $CONFIGDIR/exceptions.data.tmp
 
 # Send all instances of redirector.pl a signal to reload the data files
-if [ $RELOAD == 1 ] && [ $CHANGED == 1 ]; then
-  killall -HUP redirector.pl
+if [ "$RELOAD" = "1" ] && [ "$CHANGED" = "1" ]; then
+  echo -n "Sending signal HUP to all redirector.pl instances... "
+  for pid in $(ps wwwax | grep -i redirector.pl | grep -v grep | awk '{print $1}')
+  do
+    echo -n "$pid "
+    kill -HUP $pid
+  done
+  echo
+else
+  echo "No changes."
 fi
