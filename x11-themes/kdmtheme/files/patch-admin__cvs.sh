--- admin/cvs.sh.orig	2006-11-09 16:42:52.000000000 -0600
+++ admin/cvs.sh	2010-09-28 11:40:53.000000000 -0500
@@ -34,3 +34,3 @@
 case $AUTOCONF_VERSION in
-  Autoconf*2.5* | autoconf*2.5* ) : ;;
+  autoconf*2.6*) : ;;
   "" )
@@ -49,3 +49,3 @@
 case $AUTOHEADER_VERSION in
-  Autoconf*2.5* | autoheader*2.5* ) : ;;
+  autoheader*2.6* ) : ;;
   "" )
@@ -70,3 +70,3 @@
     ;;
-  automake*1.6.* | automake*1.7* | automake*1.8* | automake*1.9*)
+  automake*1.11* )
     echo "*** $AUTOMAKE_STRING found."
