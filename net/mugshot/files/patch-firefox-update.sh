--- firefox-update.sh.pristine	2008-04-27 22:42:09.000000000 +0530
+++ firefox-update.sh	2008-04-27 22:46:58.000000000 +0530
@@ -8,7 +8,7 @@
 
 EXT_ID=firefox@mugshot.org
 if [ "$1" = "install" ] ; then
-    for libdir in /usr/lib /usr/lib64 ; do
+	libdir=%%PREFIX%%/lib
 	# Add symlinks to any firefox directory that looks like it is part of a
 	# currently installed package
 	for d in $libdir/firefox* $libdir/iceweasel*; do
@@ -25,9 +25,8 @@
         if [ -d $libdir/mozilla/extensions -a ! -L "$link" ]; then
             ln -s $libdir/mugshot/firefox "$link"
         fi
-    done
 elif [ "$1" = "remove" ] ; then
-    for libdir in /usr/lib /usr/lib64 ; do
+	libdir=%%PREFIX%%/lib
 	# Remove any symlinks we've created into any firefox directory
 	for d in $libdir/firefox* $libdir/iceweasel*; do
 	    if [ "$d" = "$libdir/firefox*" -o "$d" = "$libdir/iceweasel*" ] ; then
@@ -38,7 +37,6 @@
 		rm $link
 	    fi
 	done
-     done
      if [ -d $libdir/mozilla/extensions ]; then
         rm $libdir/mozilla/extensions/$EXT_ID
      fi
