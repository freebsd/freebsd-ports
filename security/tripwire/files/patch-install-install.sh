--- install/install.sh.orig	2011-11-21 08:06:56.000000000 -0800
+++ install/install.sh	2012-01-26 14:46:55.995316577 -0800
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
@@ -525,7 +521,7 @@
 			chmod 0750 "$d" > /dev/null
 		fi
 	else
-		echo "$d: already exists"
+		test "$PACKAGE_INSTALLER" != "yes" && echo "$d: already exists"
 	fi
 done
 
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
