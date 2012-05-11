--- admin/cvs.sh.orig	2006-11-09 14:42:52.000000000 -0800
+++ admin/cvs.sh	2012-04-23 23:09:35.000000000 -0700
@@ -34,3 +34,3 @@
 case $AUTOCONF_VERSION in
-  Autoconf*2.5* | autoconf*2.5* ) : ;;
+  autoconf*%%AUTOCONF_VERSION%%*) : ;;
   "" )
@@ -49,3 +49,3 @@
 case $AUTOHEADER_VERSION in
-  Autoconf*2.5* | autoheader*2.5* ) : ;;
+  autoheader*%%AUTOCONF_VERSION%%* ) : ;;
   "" )
@@ -65,8 +65,3 @@
 case $AUTOMAKE_STRING in
-  automake*1.5d* | automake*1.5* | automake*1.5-* )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-  automake*1.6.* | automake*1.7* | automake*1.8* | automake*1.9*)
+  automake*%%AUTOMAKE_VERSION%%* )
     echo "*** $AUTOMAKE_STRING found."
