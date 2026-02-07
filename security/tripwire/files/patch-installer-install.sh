--- installer/install.sh.orig	2017-10-01 19:49:45.000000000 -0700
+++ installer/install.sh	2017-11-17 22:14:46.819124000 -0800
@@ -19,10 +19,6 @@
 
 PATH=".:/bin:/usr/bin:/usr/local/bin:$PATH"
 export PATH || (echo 'You must use sh to run this script'; kill $$)
-if [ ! -t 0 ] ; then
-	echo "Say 'sh install.sh', not 'sh < install.sh'"
-	exit 1
-fi
 
 ##-------------------------------------------------------
 ## The usage message.
@@ -136,17 +132,11 @@
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
@@ -162,6 +152,7 @@
 ## Parse the command line.
 ##-------------------------------------------------------
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 while [ "x$1" != "x" ] ; do
     case "$1" in
 	-n) PROMPT="false"; xCLOBBER="true" ;;
@@ -201,6 +192,7 @@
     esac
     shift
 done
+}
 
 ##-------------------------------------------------------
 ## Print the sign-on banner here before the first
@@ -301,7 +293,7 @@
 ## passphrases must be specified on the command line.
 ##-------------------------------------------------------
 
-if [ "$PROMPT" = "false" ] ; then
+if [ "$DO_NOT_CONFIG" != "yes" -a "$PROMPT" = "false" ] ; then
 	if [ -z "$TW_SITE_PASS" ] || [ -z "$TW_LOCAL_PASS" ] ; then
 		echo "Error: You must specify site and local passphrase" 1>&2
 		echo "if no prompting is chosen." 1>&2
@@ -488,7 +480,7 @@
 ##-------------------------------------------------------
 
 for i in $path2; do
-	eval "d=\$${i}"
+	eval "d=${DESTDIR}/\$${i}"
 	if [ ! -d "$d" ] ; then
 		mkdir -p "$d"
 		if [ ! -d "$d" ] ; then
@@ -499,12 +491,12 @@
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
@@ -515,7 +507,7 @@
 			chmod 0755 "$d" > /dev/null
 		fi
 	else
-		echo "$d: already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$d: already exists"
 	fi
 done
 
@@ -524,6 +516,7 @@
 ## Copy all files to the location specified.
 ##=======================================================
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 echo
 echo "----------------------------------------------"
 echo "Copying files..."
@@ -540,27 +533,31 @@
 ## Make sure README_LOC and fil1 stay in sync.
 ##-------------------------------------------------------
 
-#f1=' ff=$README ; d="" ; dd=$TWDOCS ; rr=0444 '
-#f2=' ff=$REL_NOTES ; d="" ; dd=$TWDOCS ; rr=0444 '
-f3=' ff=$TWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
-f4=' ff=tripwire ; d="/bin" ; dd=$TWBIN ; rr=0550 '
-f5=' ff=twadmin ; d="/bin" ; dd=$TWBIN ; rr=0550 '
-f6=' ff=twprint ; d="/bin" ; dd=$TWBIN ; rr=0550 '
-f7=' ff=siggen ; d="/bin" ; dd=$TWBIN ; rr=0550 '
-f8=' ff=TRADEMARK ; d="" ; dd=$TWDOCS ; rr=0444 '
-f9=' ff=policyguide.txt ; d="/policy" ; dd=$TWDOCS ; rr=0444 '
-f10=' ff=${POLICYSRC} ; d="/policy" ; dd=$TWPOLICY ; rr=0640 '
-#f11=' ff=twpolicy.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
-#f12=' ff=twconfig.4 ; d="/man/man4" ; dd=$TWMAN/man4 ; rr=0444 '
-#f13=' ff=twfiles.5 ; d="/man/man5" ; dd=$TWMAN/man5 ; rr=0444 '
-#f14=' ff=siggen.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
-#f15=' ff=tripwire.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
-#f16=' ff=twadmin.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
-#f17=' ff=twintro.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
-#f18=' ff=twprint.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
-f19=' ff=COMMERCIAL ; d="" ; dd=$TWDOCS ; rr=0444 '
-f20=' ff=ReadMe-2.4.3 ; d="" ; dd=$TWDOCS ; rr=0444 '
-f21=' ff=ChangeLog ; d="" ; dd=$TWDOCS ; rr=0444 '
+XTWDOCS=$DESTDIR/$TWDOCS
+XTWBIN=$DESTDIR/$TWBIN
+XTWPOLICY=$DESTDIR/$TWPOLICY
+XTWMAN=$DESTDIR/$TWMAN
+#f1=' ff=$README ; d="" ; dd=$XTWDOCS ; rr=0444 '
+#f2=' ff=$REL_NOTES ; d="" ; dd=$XTWDOCS ; rr=0444 '
+f3=' ff=$XTWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
+f4=' ff=tripwire ; d="/bin" ; dd=$XTWBIN ; rr=0550 '
+f5=' ff=twadmin ; d="/bin" ; dd=$XTWBIN ; rr=0550 '
+f6=' ff=twprint ; d="/bin" ; dd=$XTWBIN ; rr=0550 '
+f7=' ff=siggen ; d="/bin" ; dd=$XTWBIN ; rr=0550 '
+f8=' ff=TRADEMARK ; d="" ; dd=$XTWDOCS ; rr=0444 '
+f9=' ff=policyguide.txt ; d="/policy" ; dd=$XTWDOCS ; rr=0444 '
+f10=' ff=${POLICYSRC} ; d="/policy" ; dd=$XTWPOLICY ; rr=0640 '
+#f11=' ff=twpolicy.4 ; d="/man/man4" ; dd=$XTWMAN/man4 ; rr=0444 '
+#f12=' ff=twconfig.4 ; d="/man/man4" ; dd=$XTWMAN/man4 ; rr=0444 '
+#f13=' ff=twfiles.5 ; d="/man/man5" ; dd=$XTWMAN/man5 ; rr=0444 '
+#f14=' ff=siggen.8 ; d="/man/man8" ; dd=$XTWMAN/man8 ; rr=0444 '
+#f15=' ff=tripwire.8 ; d="/man/man8" ; dd=$XTWMAN/man8 ; rr=0444 '
+#f16=' ff=twadmin.8 ; d="/man/man8" ; dd=$XTWMAN/man8 ; rr=0444 '
+#f17=' ff=twintro.8 ; d="/man/man8" ; dd=$XTWMAN/man8 ; rr=0444 '
+#f18=' ff=twprint.8 ; d="/man/man8" ; dd=$XTWMAN/man8 ; rr=0444 '
+f19=' ff=COMMERCIAL ; d="" ; dd=$XTWDOCS ; rr=0444 '
+f20=' ff=ReadMe-2.4.3 ; d="" ; dd=$XTWDOCS ; rr=0444 '
+f21=' ff=ChangeLog ; d="" ; dd=$XTWDOCS ; rr=0444 '
 
 # Binaries and manpages are already installed by the install target
 loosefiles="f3 f4 f5 f6 f7 f8 f9 f10 f19 f20 f21"
@@ -570,7 +567,7 @@
 	f=${TAR_DIR}$d/$ff
 	ff=${dd}/$ff
 	if [ -s $ff ] && [ "$CLOBBER" = "false" ] ; then
-		echo "$ff: file already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$ff: file already exists"
 	else
 		cp "$f" "$dd"
                 if [ $? -eq 0 ]; then
@@ -581,6 +578,12 @@
 		fi
        	fi
 done
+}
+
+case $DO_NOT_CONFIG in
+yes)	exit;;
+*)	;;
+esac
 
 if [ -n "$INSTALL_STRIP_FLAG" ] ; then
   echo "INSTALL_STRIP_FLAG is set, stripping binaries"
