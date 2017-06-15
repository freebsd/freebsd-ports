--- src/src.pro.orig	2016-11-28 17:52:39 UTC
+++ src/src.pro
@@ -1,4 +1,4 @@
-TARGET = qoauth
+TARGET = qoauth-qt5
 DESTDIR = ../lib
 win32:DLLDESTDIR = $${DESTDIR}
 
@@ -78,7 +78,7 @@ else:unix {
 
     # this creates a pkgconfig file
     system( ./pcfile.sh $${INSTALL_PREFIX} $${VERSION} )
-    pkgconfig.files = qoauth.pc
+    pkgconfig.files = qoauth-qt5.pc
     
     contains(QMAKE_HOST.arch, x86_64) {
       target.path = $${INSTALL_PREFIX}/lib64
@@ -86,9 +86,9 @@ else:unix {
       target.path = $${INSTALL_PREFIX}/lib
     }
 
-    headers.path = $${INSTALL_PREFIX}/include/QtOAuth
+    headers.path = $${INSTALL_PREFIX}/include/QtOAuth-qt5/QtOAuth
     docs.path = $${INSTALL_PREFIX}/share/doc/$${TARGET}-$${VERSION}/html
-    pkgconfig.path = $${target.path}/pkgconfig
+    pkgconfig.path = $${INSTALL_PREFIX}/libdata/pkgconfig
     INSTALLS += \
         target \
         headers \
