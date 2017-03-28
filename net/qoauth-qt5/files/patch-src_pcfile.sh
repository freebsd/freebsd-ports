--- src/pcfile.sh.orig	2016-11-28 17:52:39 UTC
+++ src/pcfile.sh
@@ -5,11 +5,11 @@
 echo "prefix=$1
 exec_prefix=\${prefix}
 libdir=\${prefix}/lib
-includedir=\${prefix}/include/QtOAuth
+includedir=\${prefix}/include/QtOAuth-qt5
 
-Name: QOAuth
+Name: QOAuth-qt5
 Description: Qt OAuth support library
 Version: $2
-Requires: QtCore QtNetwork qca2
-Libs: -L\${libdir} -lqoauth
-Cflags: -I\${includedir}" > qoauth.pc
+Requires: Qt5Core Qt5Network qca2-qt5
+Libs: -L\${libdir} -lqoauth-qt5
+Cflags: -I\${includedir}" > qoauth-qt5.pc
