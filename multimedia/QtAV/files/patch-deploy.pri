--- deploy.pri.orig	2017-04-06 20:22:41 UTC
+++ deploy.pri
@@ -4,7 +4,7 @@ INSTALL_PREFIX = /usr/local
 share.files = $$PROJECTROOT/qtc_packaging/common/changelog \
 			$$PROJECTROOT/qtc_packaging/common/copyright \
 			$$PROJECTROOT/qtc_packaging/common/README
-share.path = /usr/share/doc/$${TARGET}
+share.path = $$[QT_INSTALL_PREFIX]/share/doc/$${TARGET}
 
 isEqual(TEMPLATE, app) {
 	unix:!symbian {
@@ -25,9 +25,9 @@ isEqual(TEMPLATE, app) {
 			#debian.files = $$PROJECTROOT/qtc_packaging/fremantle/control
 		} else {
 			desktopfile.files = $$PROJECTROOT/qtc_packaging/debian_generic/$${TARGET}.desktop
-			desktopfile.path = /usr/share/applications
+			desktopfile.path = $$[QT_INSTALL_PREFIX]/share/applications
 			icon.files = $$PROJECTROOT/qtc_packaging/debian_generic/$${TARGET}.png
-			icon.path = /usr/share/icons/hicolor/64x64/apps
+			icon.path = $$[QT_INSTALL_PREFIX]/share/icons/hicolor/64x64/apps
 			#debian.files = $$PROJECTROOT/qtc_packaging/generic/control
 		}
 		INSTALLS += desktopfile icon
@@ -41,9 +41,9 @@ isEqual(TEMPLATE, app) {
 		isEmpty(SDK_HEADERS) {
 			sdkheaders.files = $$HEADERS
 		}
-                sdkheaders.path = $$[QT_INSTALL_HEADERS]/$$MODULE_INCNAME
-                sdkheaders_private.path = $$[QT_INSTALL_HEADERS]/$$MODULE_INCNAME/$$MODULE_VERSION/$$MODULE_INCNAME/private
-                !plugin: target.path = $$[QT_INSTALL_LIBS]
+                sdkheaders.path = $$[QT_INSTALL_PREFIX]/include/$$MODULE_INCNAME
+                sdkheaders_private.path = $$[QT_INSTALL_PREFIX]/include/$$MODULE_INCNAME/$$MODULE_VERSION/$$MODULE_INCNAME/private
+                !plugin: target.path = $$[QT_INSTALL_PREFIX]/lib
                 INSTALLS += sdkheaders sdkheaders_private
 	}
 }
@@ -51,7 +51,7 @@ isEqual(TEMPLATE, app) {
 INSTALLS *= target share
 
 for(bin, BIN_INSTALLS) {
-    eval($${bin}.path = $${INSTALL_PREFIX}/bin)
+    eval($${bin}.path = $$[QT_INSTALL_PREFIX]/bin)
     message("adding $$bin to bin install targets...")
     INSTALLS += $$bin
 }
