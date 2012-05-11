--- admin/cvs.sh.orig	2008-07-07 13:38:56.000000000 -0700
+++ admin/cvs.sh	2012-04-24 09:34:37.000000000 -0700
@@ -65,8 +65,3 @@
 case $AUTOMAKE_STRING in
-  automake*1.5d* | automake*1.5* | automake*1.5-* )
-    echo "*** YOU'RE USING $AUTOMAKE_STRING."
-    echo "*** KDE requires automake $required_automake_version"
-    exit 1
-    ;;
-  automake*1.6.* | automake*1.7* | automake*1.8* | automake*1.9* | automake*1.10*)
+  automake*%%AUTOMAKE_VERSION%%* )
     echo "*** $AUTOMAKE_STRING found."
