--- firefox-update.sh.orig	Sun Dec 24 22:31:37 2006
+++ firefox-update.sh	Sun Dec 24 22:34:38 2006
@@ -6,7 +6,7 @@
 # Firefox is installed into versioned directories in /usr/lib[64]/firefox
 #
 if [ "$1" = "install" ] ; then
-    for libdir in /usr/lib /usr/lib64 ; do
+	libdir=%%PREFIX%%/lib
 	# Add symlinks to any firefox directory that looks like it is part of a
 	# currently installed package
 	for d in $libdir/firefox* ; do
@@ -19,9 +19,8 @@
 		ln -s $target $link
 	    fi
 	done
-    done
 elif [ "$1" = "remove" ] ; then
-    for libdir in /usr/lib /usr/lib64 ; do
+	libdir=%%PREFIX%%/lib
 	# Remove any symlinks we've created into any firefox directory
 	for d in $libdir/firefox* ; do
 	    if [ d = "$libdir/firefox*" ] ; then
@@ -32,7 +31,6 @@
 		rm $link
 	    fi
 	done
-     done
 else
     echo "Usage firefox-update.sh [install/remove]"
 fi
