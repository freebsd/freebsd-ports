--- src/src.pro.orig	2012-01-07 23:02:25.327074206 +0000
+++ src/src.pro	2012-01-07 23:06:28.619562777 +0000
@@ -174,12 +174,12 @@
 
 # Installation
 headers.files = $$INSTALL_HEADERS
-headers.path = $$[QT_INSTALL_PREFIX]/include/qxmpp
-target.path = $$[QT_INSTALL_LIBS]
+headers.path = $$PREFIX/include/qxmpp
+target.path = $$PREFIX/%%QT_LIBDIR_REL%%
 INSTALLS += headers target
 
 # pkg-config support
 CONFIG += create_pc create_prl no_install_prl
-QMAKE_PKGCONFIG_DESTDIR = $$QXMPP_LIBRARY_DIR/pkgconfig
+QMAKE_PKGCONFIG_DESTDIR = $$QXMPP_LIBRARY_DIR/../../libdata/pkgconfig
 QMAKE_PKGCONFIG_LIBDIR = $$target.path
 QMAKE_PKGCONFIG_INCDIR = $$headers.path
