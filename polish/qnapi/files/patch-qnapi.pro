--- qnapi.pro.orig	2008-05-20 18:50:01.000000000 +0200
+++ qnapi.pro	2010-11-27 13:38:04.000000000 +0100
@@ -77,7 +77,7 @@
 #QMAKE_BUNDLE_DATA += 7ZIP_BINARY
 }
 unix {
- INSTALL_PREFIX =  /usr
+ INSTALL_PREFIX =  $$PREFIX
  target.path =  $${INSTALL_PREFIX}/bin
  doc.path =  $${INSTALL_PREFIX}/share/doc/$${TARGET}
  doc.files =  doc/ChangeLog \
@@ -89,27 +89,24 @@
   doc/COPYRIGHT \
   doc/qnapi-download.desktop \
   doc/qnapi-download.schemas
- man.path =  $${INSTALL_PREFIX}/share/man/man1
+ man.path =  $${INSTALL_PREFIX}/man/man1
  man.files =  doc/$${TARGET}.1.gz
- icons.path =  /usr/share/icons
+ icons.path =  $${INSTALL_PREFIX}/share/icons
  icons.files =  res/qnapi.png  res/qnapi-48.png  res/qnapi-128.png  res/qnapi-512.png
- desktop.path =  /usr/share/applications
+ desktop.path =  $${INSTALL_PREFIX}/share/applications
  desktop.files =  doc/$${TARGET}.desktop
  dolphin_integration.path =  /usr/share/apps/dolphin/servicemenus
  dolphin_integration.files =  doc/$${TARGET}-download.desktop
  d3lphin_integration.path =  /usr/share/apps/d3lphin/servicemenus
  d3lphin_integration.files =  doc/$${TARGET}-download.desktop
- konqueror_integration.path =  /usr/share/apps/konqueror/servicemenus
+ konqueror_integration.path =  $${INSTALL_PREFIX}/share/apps/konqueror/servicemenus
  konqueror_integration.files =  doc/$${TARGET}-download.desktop
- kde4_integration.path =  /usr/lib/kde4/share/kde4/services/ServiceMenus
+ kde4_integration.path =  $$KDE4_PREFIX/share/kde4/services/ServiceMenus
  kde4_integration.files =  doc/$${TARGET}-download.desktop
  INSTALLS =  target \
-  doc \
   man \
   icons \
   desktop \
-  dolphin_integration \
-  d3lphin_integration \
   konqueror_integration \
   kde4_integration
 }
