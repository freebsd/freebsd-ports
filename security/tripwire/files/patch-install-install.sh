--- install/install.sh.orig	2011-11-21 08:06:56.000000000 -0800
+++ install/install.sh	2014-06-01 20:55:20.632399290 -0700
@@ -174,17 +174,11 @@
 # Starting directory.
 START_DIR=`pwd`
 
-# Site passphrase.
-TW_SITE_PASS=""
-
-# Local passphrase.
-TW_LOCAL_PASS=""
-
 # If clobber==true, overwrite files; if false, do not overwrite files.
-CLOBBER="false"
+CLOBBER=${TW_CLOBBER:-"false"}
 
 # If prompt==true, ask for confirmation before continuing with install.
-PROMPT="true"
+PROMPT=${TW_PROMPT:-"true"}
 
 # Guess where the toplevel for the distribution is.
 # A bad guess is the current directory
@@ -200,6 +194,7 @@
 ## Parse the command line.
 ##-------------------------------------------------------
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 while [ "x$1" != "x" ] ; do
     case "$1" in
 	-n) PROMPT="false"; xCLOBBER="true" ;;
@@ -232,6 +227,7 @@
     esac
     shift
 done
+}
 
 ##-------------------------------------------------------
 ## Print the sign-on banner here before the first
@@ -333,7 +329,7 @@
 ## passphrases must be specified on the command line.
 ##-------------------------------------------------------
 
-if [ "$PROMPT" = "false" ] ; then
+if [ "$DO_NOT_CONFIG" != "yes" -a "$PROMPT" = "false" ] ; then
 	if [ -z "$TW_SITE_PASS" ] || [ -z "$TW_LOCAL_PASS" ] ; then
 		echo "Error: You must specify site and local passphrase" 1>&2
 		echo "if no prompting is chosen." 1>&2
@@ -514,7 +510,7 @@
 ##-------------------------------------------------------
 
 for i in $path2; do
-	eval "d=\$${i}"
+	eval "d=${DESTDIR}/\$${i}"
 	if [ ! -d "$d" ] ; then
 		mkdir -p "$d"
 		if [ ! -d "$d" ] ; then
@@ -525,12 +521,12 @@
 			chmod 0750 "$d" > /dev/null
 		fi
 	else
-		echo "$d: already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$d: already exists"
 	fi
 done
 
 for i in $path3; do
-	eval "d=\$${i}"
+	eval "d=${DESTDIR}/\$${i}"
 	if [ ! -d "$d" ] ; then
 		mkdir -p "$d"
 		if [ ! -d "$d" ] ; then
@@ -541,7 +537,7 @@
 			chmod 0755 "$d" > /dev/null
 		fi
 	else
-		echo "$d: already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$d: already exists"
 	fi
 done
 
@@ -550,6 +546,7 @@
 ## Copy all files to the location specified.
 ##=======================================================
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 echo
 echo "----------------------------------------------"
 echo "Copying files..."
@@ -568,14 +565,14 @@
 
 #f1=' ff=$README ; d="" ; dd=$TWDOCS ; rr=0444 '
 #f2=' ff=$REL_NOTES ; d="" ; dd=$TWDOCS ; rr=0444 '
-f3=' ff=$TWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
+f3=' ff=$TWLICENSEFILE ; d="" ; dd=$DESTDIR/$TWDOCS ; rr=0444 '
 #f4=' ff=tripwire ; d="/bin" ; dd=$TWBIN ; rr=0550 '
 #f5=' ff=twadmin ; d="/bin" ; dd=$TWBIN ; rr=0550 '
 #f6=' ff=twprint ; d="/bin" ; dd=$TWBIN ; rr=0550 '
 #f7=' ff=siggen ; d="/bin" ; dd=$TWBIN ; rr=0550 '
-f8=' ff=TRADEMARK ; d="" ; dd=$TWDOCS ; rr=0444 '
-f9=' ff=policyguide.txt ; d="/policy" ; dd=$TWDOCS ; rr=0444 '
-f10=' ff=${POLICYSRC} ; d="/policy" ; dd=$TWPOLICY ; rr=0640 '
+f8=' ff=TRADEMARK ; d="" ; dd=$DESTDIR/$TWDOCS ; rr=0444 '
+f9=' ff=policyguide.txt ; d="/policy" ; dd=$DESTDIR/$TWDOCS ; rr=0444 '
+f10=' ff=${POLICYSRC} ; d="/policy" ; dd=$DESTDIR/$TWPOLICY ; rr=0640 '
 #f11=' ff=twpolicy.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
 #f12=' ff=twconfig.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
 #f13=' ff=twfiles.5 ; d="/man/man5" ; dd=$TWMAN/man5 ; rr=0444 '
@@ -593,7 +590,7 @@
 	f=${TAR_DIR}$d/$ff
 	ff=${dd}/$ff
 	if [ -s $ff ] && [ "$CLOBBER" = "false" ] ; then
-		echo "$ff: file already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$ff: file already exists"
 	else
 		cp "$f" "$dd"
                 if [ $? -eq 0 ]; then
@@ -604,6 +601,12 @@
 		fi
        	fi
 done
+}
+
+case $DO_NOT_CONFIG in
+yes)	exit;;
+*)	;;
+esac
 
 ##=======================================================
 ## Files are now present on user's system.
