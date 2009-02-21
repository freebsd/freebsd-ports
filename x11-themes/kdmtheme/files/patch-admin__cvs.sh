--- ./admin/cvs.sh.orig	2006-11-10 01:42:52.000000000 +0300
+++ ./admin/cvs.sh	2007-12-17 21:13:50.000000000 +0300
@@ -32,7 +32,7 @@
 required_autoconf_version="2.53 or newer"
 AUTOCONF_VERSION=`$AUTOCONF --version | head -n 1`
 case $AUTOCONF_VERSION in
-  Autoconf*2.5* | autoconf*2.5* ) : ;;
+  Autoconf*2.5* | autoconf*2.5* | autoconf*2.6*) : ;;
   "" )
     echo "*** AUTOCONF NOT FOUND!."
     echo "*** KDE requires autoconf $required_autoconf_version"
@@ -47,7 +47,7 @@
 
 AUTOHEADER_VERSION=`$AUTOHEADER --version | head -n 1`
 case $AUTOHEADER_VERSION in
-  Autoconf*2.5* | autoheader*2.5* ) : ;;
+  Autoconf*2.5* | autoheader*2.5* | autoheader*2.6* ) : ;;
   "" )
     echo "*** AUTOHEADER NOT FOUND!."
     echo "*** KDE requires autoheader $required_autoconf_version"
