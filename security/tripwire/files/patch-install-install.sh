--- install/install.sh.orig	2011-11-21 08:06:56.000000000 -0800
+++ install/install.sh	2012-01-17 22:57:34.124821110 -0800
@@ -200,6 +200,7 @@
 ## Parse the command line.
 ##-------------------------------------------------------
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 while [ "x$1" != "x" ] ; do
     case "$1" in
 	-n) PROMPT="false"; xCLOBBER="true" ;;
@@ -232,6 +233,7 @@
     esac
     shift
 done
+}
 
 ##-------------------------------------------------------
 ## Print the sign-on banner here before the first
@@ -550,6 +552,7 @@
 ## Copy all files to the location specified.
 ##=======================================================
 
+test "$PACKAGE_INSTALLER" != "yes" && {
 echo
 echo "----------------------------------------------"
 echo "Copying files..."
@@ -604,6 +607,12 @@
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
