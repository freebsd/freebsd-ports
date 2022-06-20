--- edfbrowser.pro.orig	2022-06-20 06:49:59 UTC
+++ edfbrowser.pro
@@ -284,35 +284,35 @@ win32 {
 QMAKE_CXXFLAGS += -Wextra -Wshadow -Wformat -Wformat-nonliteral -Wformat-security -Wtype-limits -Wfatal-errors -Wdeprecated-declarations
 
 unix {
-target.path = /usr/bin
+target.path = $$PREFIX/bin/
 target.files = edfbrowser
 INSTALLS += target
 
-documentation.path = /usr/share/doc/edfbrowser
+documentation.path = $$PREFIX/share/doc/edfbrowser
 documentation.files = doc/*
 INSTALLS += documentation
 
-icon_a.path = /usr/share/icons
+icon_a.path = $$PREFIX/share/icons
 icon_a.files = images/edf.png
 INSTALLS += icon_a
 
-icon_b.path += /usr/share/pixmaps
+icon_b.path += $$PREFIX/share/pixmaps
 icon_b.files = images/edf.png
 INSTALLS += icon_b
 
-icon_c.path += /usr/share/icons/hicolor/48x48/apps
+icon_c.path += $$PREFIX/share/icons/hicolor/48x48/apps
 icon_c.files = images/edf.png
 INSTALLS += icon_c
 
-icon_d.path += /usr/share/icons/hicolor/48x48/mimetypes
+icon_d.path += $$PREFIX/share/icons/hicolor/48x48/mimetypes
 icon_d.files = images/edf.png
 INSTALLS += icon_d
 
-desktop_link.path += /usr/share/applications
+desktop_link.path += $$PREFIX/share/applications
 desktop_link.files += install/edfbrowser.desktop
 INSTALLS += desktop_link
 
-mime.path += /usr/share/mime/packages
+mime.path += $$PREFIX/share/mime/packages
 mime.files += install/edfbrowser.xml
 INSTALLS += mime
 }
@@ -323,10 +323,10 @@ mac {
  QMAKE_APPLICATION_BUNDLE_NAME = EDFbrowser
  QMAKE_TARGET_BUNDLE_PREFIX = net.teuniz
  icns.target = edf.icns
- icns.commands = /usr/bin/env bash $$_PRO_FILE_PWD_/images/macos-icns-create.command "$$(PWD)"
+ icns.commands = $$PREFIX/bin/env bash $$_PRO_FILE_PWD_/images/macos-icns-create.command "$$(PWD)"
  QMAKE_EXTRA_TARGETS += icns
  ICON = $$(PWD)/edf.icns
- QMAKE_POST_LINK = /usr/bin/env bash $$_PRO_FILE_PWD_/install/macos-dmg-create.command "$$(PWD)"
+ QMAKE_POST_LINK = $$PREFIX/bin/env bash $$_PRO_FILE_PWD_/install/macos-dmg-create.command "$$(PWD)"
  QMAKE_CLEAN += edf.iconset EDFbrowser-*-temp.dmg
  QMAKE_DISTCLEAN += edf.icns EDFbrowser-*.dmg
 }
